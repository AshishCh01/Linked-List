#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// insertion at head or beginning in LL
void insertAtHead(Node* &head, int d) { // (&) reference is taken because we want to change original LL
    
    // new node created
    Node* temp = new Node(d);   // whenever a new data is inserted a new node is created
    temp -> next = head;
    head = temp;
}

// insertion at tail or end in LL
void insertAtTail(Node* &tail, int d) {
    // new node created
    Node* temp = new Node(d);   // whenever a new data is inserted a new node is created
    tail -> next = temp;
    tail = tail -> next;
}

// traversing LL
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    // created a new node
    Node* node1 = new Node(10);
    // cout << node1 -> data <<endl;
    // cout << node1 -> next << endl;
    
    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    insertAtTail(tail, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);
    
    // insertAtHead(head, 12);
    // print(head);
    
    // insertAtHead(head, 15);
    // print(head);
    
    return 0;
}