#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    public:
    Node(int data1, Node* next1, Node* prev1) {
        this->data = data1;
        this->next = next1;
        this->prev = prev1;
    }
    
    public:
    Node(int data1) {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
Node* arrayToDLL(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i=1; i<n; i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToDLL(arr, n);

    print(head);

    return 0;
}