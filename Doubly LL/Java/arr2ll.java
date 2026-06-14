class Node {
    int data;
    Node next;
    Node prev;

    Node(int data, Node next, Node prev) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }
    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
};
public class arr2ll {

    static Node convertArr2DLL(int[] arr, int n) {
        if (n == 0) {
            return null;
        }
        Node head = new Node(arr[0]);
        Node prev = head;
        for (int i = 1; i < n; i++) {
            Node temp = new Node(arr[i]);
            prev.next = temp;
            // temp.prev = prev;
            // prev = prev.next;
            prev = temp;
        }
        return head;
    }

    static void print(Node head) {
        Node prev = head;
        while (prev != null) {
            System.out.print(prev.data + " ");
            prev = prev.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        int n = arr.length;
        Node head = convertArr2DLL(arr, n);
        print(head);
    }
}