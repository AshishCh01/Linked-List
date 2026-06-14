#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    // Constructor
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

Node* reverseSLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;
    while(current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

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
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = arrayToDLL(arr);
    head = reverseSLL(head);
    print(head);
    return 0;
}