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

    int count0 = 0, count1 = 0, count2 = 0;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
        if (count0) {
            temp->data = 0;
            count0--;
        }
        else if (count1) {
            temp->data = 1;
            count1--;
        }
        else {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

int main() {

    vector<int> v = {0,1,2,0,1,2};

    Node* head = vectorToLL(v);

    head = sortZeroOneTwo(head);

    print(head);

    return 0;
}