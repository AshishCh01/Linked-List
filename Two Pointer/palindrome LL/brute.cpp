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

bool isPalindrome(Node* head) {
    // Create an empty stack to store values
    stack<int> st;
    Node* temp = head;
    
    // Traverse the linked list and push values onto the stack
    while(temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;    // Reset the temporary pointer back to the head of the linked list
    
    while(temp != NULL) {
        if(temp->data != st.top()) return false;    // If values don't match, it's not a palindrome
        temp = temp->next;  // Move to the next node in the linked list
        st.pop();   // Pop the value from the stack
    }
    return true;    // If all values match, it's a palindrome
}
int main()
{
    vector<int> arr = {1,2,2,1};
    Node* head = arrayToLL(arr);
    cout << isPalindrome(head);
    return 0;
}