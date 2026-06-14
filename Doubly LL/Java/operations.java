
class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
    Node(int data, Node prev, Node next) {
        this.data = data;
        this.prev = prev;
        this.next = next;
    }
}
public class operations {
    
    static Node convertArr2DLL(int[] arr) {
        if (arr.length == 0)
            return null;
        // First node
        Node head = new Node(arr[0]);
        Node tail = head;
        
        // Remaining nodes
        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            // Forward link
            tail.next = temp;
            // Backward link
            temp.prev = tail;
            // Move tail
            tail = temp;
        }
        return head;
    }
    
    static Node deleteHead(Node head) {
        if (head == null || head.next == null) return null;
        
        Node prev = head;
        head = head.next;
        
        head.prev = null;
        prev.next = null;
        return head;
    }

    static Node deleteTail(Node head) {
        if (head == null || head.next == null) return null;
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }
        Node newTail = tail.prev;
        newTail.next = null;
        tail.prev = null;
        return head;
    }

    // deleting kth position
    static Node removeKthElement(Node head, int k) {
        if (head == null) return null;
    
        int cnt = 0;
        Node kNode = head;
    
        while (kNode != null) {
            cnt++;
            if (cnt == k) break;
            kNode = kNode.next;
        }
    
        if (kNode == null) return head;
    
        Node prev = kNode.prev;
        Node front = kNode.next;
    
        if (prev == null && front == null) {
            return null;
        }
        else if (prev == null) {
            return deleteHead(head);
        }
        else if (front == null) {
            return deleteTail(head);
        }
    
        prev.next = front;
        front.prev = prev;
    
        kNode.next = null;
        kNode.prev = null;
    
        return head;
    }

    // deleting node by position of the head
   static void deleteNode(Node temp) {
        Node prev = temp.prev;
        Node front = temp.next;
        if(front == null) {
            prev.next = null;
            temp.prev = null;
            return;
        }
        prev.next = front;
        front.prev = prev;
        
        temp.next = temp.prev = null; 
    }

    // insertion operations
     static Node insertBeforeHead(Node head, int val) {
        Node newHead = new Node(val, null, head);
        head.prev = newHead;
        return newHead;
    }

    static Node insertBeforeTail(Node head, int val) {
        if (head == null) return new Node(val);
        if (head.next == null) {
            return insertBeforeHead(head, val);
        }
        Node tail = head;
    
        while (tail.next != null) {
            tail = tail.next;
        }
        Node prev = tail.prev;
    
        // prev node first, tail node second
        Node newNode = new Node(val, prev, tail);
    
        prev.next = newNode;
        tail.prev = newNode;
        return head;
    }
    
    static Node insertBeforeKthElement(Node head, int k, int val) {
    // Invalid position
        if (k <= 0) return head;
    
        // Insert before head (position 1)
        if (k == 1) {
            return insertBeforeHead(head, val);
        }
    
        Node temp = head;
        int cnt = 0;
    
        while (temp != null) {
            cnt++;
            if (cnt == k) break;
            temp = temp.next;
        }
    
        // k is greater than list length
        if (temp == null) return head;
        Node prev = temp.prev;
        Node newNode = new Node(val, prev, temp);
    
        prev.next = newNode;
        temp.prev = newNode;
    
        return head;
    }
    
    static Node insertBeforeNode(Node head, Node temp, int val) {
        // If temp is the head node
        if (temp == head) {
            return insertBeforeHead(head, val);
        }
    
        Node prev = temp.prev;
    
        Node newNode = new Node(val, prev, temp);
    
        prev.next = newNode;
        temp.prev = newNode;
    
        return head;
    }
    
    static void print(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

	public static void main(String[] args) {
		int[] arr = {10, 20, 30, 40, 50};
        Node head = convertArr2DLL(arr);
        // head = deleteTail(head);
        // head = deleteTail(head);
       // head = removeKthElement(head, 2);
        // deleteNode(head->next->next);
       // head = insertBeforeHead(head, 9);
        // head = insertBeforeTail(head, 60);
       //  head = insertBeforeKthElement(head, 4, 90);
        head = insertBeforeNode(head, head.next.next, 25);
        print(head);
	}
}
