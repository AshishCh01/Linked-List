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

// insert at any position
void insertAtAnyPosition(Node* &head, Node* &tail, int position, int d) {
    // inserting at first position
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }
    
    // find the node before the target position
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    
    // inserting at last position
    if (temp -> next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    
    // insertion in the middle
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


// Deletion
void deleteNode(Node* &head, Node* &tail, int position) {

    // deleting first node
    
    if(position == 1) {
        Node* temp = head;
        head = head->next;

        if(head == NULL)
            tail = NULL;

        delete temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    int cnt = 1;

    while(cnt < position) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    // deleting last node
    if(curr == tail)
        tail = prev;

    prev->next = curr->next;

    delete curr;
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
    
    insertAtHead(head, 12);
    print(head);
    
    insertAtHead(head, 15);
    print(head);
    
    insertAtAnyPosition(head, tail, 3, 22);
    deleteNode(head, tail, 2);
    print(head);
    
    return 0;
}