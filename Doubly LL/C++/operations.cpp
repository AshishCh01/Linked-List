#include <iostream>
#include <vector>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    public:
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

Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    
    Node* prev = head;
    head = head->next;
    
    head->prev = nullptr;
    prev->next = nullptr;
    
    delete prev;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

// deleting kth position
Node* removeKthElement(Node* head, int k) {
    if (head == NULL) return NULL;

    int cnt = 0;
    Node* kNode = head;

    while (kNode != NULL) {
        cnt++;
        if (cnt == k) break;
        kNode = kNode->next;
    }

    if (kNode == NULL) return head;

    Node* prev = kNode->prev;
    Node* front = kNode->next;

    if (prev == NULL && front == NULL) {
        delete kNode;
        return NULL;
    }
    else if (prev == NULL) {
        return deleteHead(head);
    }
    else if (front == NULL) {
        return deleteTail(head);
    }

    prev->next = front;
    front->prev = prev;

    kNode->next = nullptr;
    kNode->prev = nullptr;

    delete kNode;

    return head;
}

// deleting node by position of the head
void deleteNode(Node* temp) {
    Node* prev = temp->prev;
    Node* front = temp->next;
    if(front == NULL) {
        prev->next = nullptr;
        temp->prev = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->prev = prev;
    
    temp->next = temp->prev = nullptr;
    free(temp); // or delete temp
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, nullptr, head);
    head->prev = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head == NULL) return new Node(val);
    if (head->next == NULL) {
        return insertBeforeHead(head, val);
    }
    Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* prev = tail->prev;

    // prev node first, tail node second
    Node* newNode = new Node(val, prev, tail);

    prev->next = newNode;
    tail->prev = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
    // Invalid position
    if (k <= 0) return head;

    // Insert before head (position 1)
    if (k == 1) {
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    // k is greater than list length
    if (temp == NULL) return head;

    Node* prev = temp->prev;

    Node* newNode = new Node(val, prev, temp);

    prev->next = newNode;
    temp->prev = newNode;

    return head;
}

Node* insertBeforeNode(Node* head, Node* temp, int val) {
    // If temp is the head node
    if (temp == head) {
        return insertBeforeHead(head, val);
    }

    Node* prev = temp->prev;

    Node* newNode = new Node(val, prev, temp);

    prev->next = newNode;
    temp->prev = newNode;

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
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = arrayToDLL(arr);
    // head = deleteTail(head);
    // head = deleteTail(head);
   // head = removeKthElement(head, 2);
    // deleteNode(head->next->next);
   // head = insertBeforeHead(head, 9);
    // head = insertBeforeTail(head, 60);
   //  head = insertBeforeKthElement(head, 4, 90);
    head = insertBeforeNode(head, head->next->next, 25);
    print(head);
    return 0;
}