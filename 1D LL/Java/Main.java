// Singly Linked List Operations in Java

public class Main {

    // Node class
    static class Node {
        int data;
        Node next;

        // Constructor
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Wrapper class to simulate pass-by-reference for head and tail
    static class LinkedList {
        Node head;
        Node tail;
    }

    // ---------------------------------------------------------
    // Insert at Head
    // ---------------------------------------------------------
    static void insertAtHead(LinkedList list, int d) {

        Node temp = new Node(d);

        temp.next = list.head;
        list.head = temp;

        // If list was empty
        if (list.tail == null) {
            list.tail = temp;
        }
    }

    // ---------------------------------------------------------
    // Insert at Tail
    // ---------------------------------------------------------
    static void insertAtTail(LinkedList list, int d) {

        Node temp = new Node(d);

        // Empty list
        if (list.head == null) {
            list.head = temp;
            list.tail = temp;
            return;
        }

        list.tail.next = temp;
        list.tail = temp;
    }

    // ---------------------------------------------------------
    // Insert at Any Position
    // ---------------------------------------------------------
    static void insertAtAnyPosition(LinkedList list, int position, int d) {

        // Insert at first position
        if (position == 1) {
            insertAtHead(list, d);
            return;
        }

        Node temp = list.head;
        int cnt = 1;

        while (cnt < position - 1) {
            temp = temp.next;
            cnt++;
        }

        // Insert at last position
        if (temp.next == null) {
            insertAtTail(list, d);
            return;
        }

        // Insert in middle
        Node nodeToInsert = new Node(d);

        nodeToInsert.next = temp.next;
        temp.next = nodeToInsert;
    }

    // ---------------------------------------------------------
    // Delete Node
    // ---------------------------------------------------------
    static void deleteNode(LinkedList list, int position) {

        // Delete first node
        if (position == 1) {

            Node temp = list.head;
            list.head = list.head.next;

            // If list becomes empty
            if (list.head == null) {
                list.tail = null;
            }

            temp.next = null;
            return;
        }

        Node prev = null;
        Node curr = list.head;

        int cnt = 1;

        while (cnt < position) {
            prev = curr;
            curr = curr.next;
            cnt++;
        }

        // Update tail if deleting last node
        if (curr == list.tail) {
            list.tail = prev;
        }

        prev.next = curr.next;
        curr.next = null;
    }

    // ---------------------------------------------------------
    // Print Linked List
    // ---------------------------------------------------------
    static void print(LinkedList list) {

        Node temp = list.head;

        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }

        System.out.println();
    }

    // ---------------------------------------------------------
    // Main Function
    // ---------------------------------------------------------
    public static void main(String[] args) {

        LinkedList list = new LinkedList();

        // Create first node
        Node node1 = new Node(10);

        list.head = node1;
        list.tail = node1;

        print(list);

        insertAtTail(list, 12);
        print(list);

        insertAtTail(list, 15);
        print(list);

        insertAtHead(list, 11);
        print(list);

        insertAtHead(list, 113);
        print(list);

        insertAtAnyPosition(list, 3, 22);

        deleteNode(list, 2);

        print(list);
    }
}