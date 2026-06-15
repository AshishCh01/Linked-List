#include <bits/stdc++.h>
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
Node* arrayToDLL(vector<int>arr) {
    // If vector is empty
    if (arr.size() == 0) {
        return NULL;
    }

    // Create head node
    Node* head = new Node(arr[0]);
    Node* temp = head;

    // Create remaining nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        //newNode->prev = temp;
        temp = newNode;
    }

    return head; 
}

Node* addTwonumbers(Node* l1, Node* l2) {
    Node *dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = l1;
    Node* temp2 = l2;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum/10;
        
        curr->next = newNode;
        curr = curr->next;
        
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
}

// Print linked list
void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    vector<int> l1 = {1, 2, 3, 4, 5};
    vector<int> l2 = {1, 5, 6, 7};
    Node* head1 = arrayToDLL(l1);
    Node* head2 = arrayToDLL(l2);
    
    Node* result = addTwonumbers(head1, head2);
    print(result);
    return 0;
}