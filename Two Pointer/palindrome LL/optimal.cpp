#include <iostream>
#include<vector>
#include <stack>
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

Node* arrayToLL(vector<int>& arr) {
    int n = arr.size();
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

// Iterative approach
Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverseLinkedList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindrome(Node* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }
    
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;  // move slow one step
        fast = fast->next->next;    // move fast two steps
    }
    
    
     // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    Node* first = head;

    // Pointer to the reversed second half
    Node* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->data != second->data) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}

int main()
{
    vector<int> arr = {1,2};
    Node* head = arrayToLL(arr);
    cout << isPalindrome(head);
    return 0;
}