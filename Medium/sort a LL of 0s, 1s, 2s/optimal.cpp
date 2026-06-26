#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* vectorToLL(vector<int>& v) {
    if (v.empty())
        return nullptr;

    Node* head = new Node(v[0]);
    Node* tail = head;

    for (int i = 1; i < v.size(); i++) {
        Node* temp = new Node(v[i]);
        tail->next = temp;
        tail = temp;
    }

    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* sortZeroOneTwo(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    // Create dummy nodes for three lists: 0s, 1s, and 2s
    Node* zeroDummy = new Node(-1);
    Node* oneDummy = new Node(-1);
    Node* twoDummy = new Node(-1);
    // Tail pointers to build each of the lists
    Node* zeroTail = zeroDummy;
    Node* oneTail = oneDummy;
    Node* twoTail = twoDummy;
    
    Node* temp = head;
    // Traverse original list and distribute nodes into 0s, 1s, or 2s list
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;  //OR zeroTail = zeroTail->next;
        }
        else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        }
        else {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = temp->next;
    }
    
    // Connect the three lists:
    // zeroTail -> oneDummy.next -> twoDummy.next
    // Handle edge cases if 0s or 1s list is empty
    zeroTail->next = (oneDummy->next) ? (oneDummy->next) : (twoDummy->next);
    oneTail->next = twoDummy->next;
    twoTail->next = nullptr;
    
    // Update head to new sorted list
    Node* newHead = zeroDummy->next;
    
    // Delete dummy nodes (they were placeholders)
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;
    
    return newHead;
}

int main()
{
    vector<int> v = {0,1,2,0,1,2};

    Node* head = vectorToLL(v);

    head = sortZeroOneTwo(head);

    print(head);
    return 0;
}