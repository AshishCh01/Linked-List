#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* arrayToLL(int arr[], int n) {

    // Empty array
    if (n == 0)
        return NULL;

    // First node
    Node* head = new Node(arr[0]);
    Node* tail = head;

    // Remaining nodes
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }

    return head;
}

Node* middleNode(Node* head) {
    // Initialize the slow and fast pointer to the head
    Node* slow = head;
    Node* fast = head;
    
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  // move slow one step
        fast = fast->next->next;    // move fast two steps
    }
    return slow;
}
int main()
{
    int arr[] = {12,5,6,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToLL(arr, n);
    Node* mid = middleNode(head);

    cout << mid->data;
    return 0;
}