
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node* arrayToDLL(vector<int>arr) {
     int n = arr.size();
    if (n == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);

        prev->next = temp;   // forward link
        temp->prev = prev;   // backward link

        prev = temp;
    }

    return head;
}

Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        
        current = current->prev;
    }
    return prev->prev;
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
    head = reverseDLL(head);
    print(head);
    return 0;
}