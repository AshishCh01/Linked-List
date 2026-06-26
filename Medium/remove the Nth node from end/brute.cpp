#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

ListNode* vectorToLL(vector<int>& v) {
    if (v.empty())
        return nullptr;

    ListNode* head = new ListNode(v[0]);
    ListNode* tail = head;

    for (int i = 1; i < v.size(); i++) {
        ListNode* temp = new ListNode(v[i]);
        tail->next = temp;
        tail = temp;
    }

    return head;
}

void print(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    ListNode* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    if(count == n) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    int res = count-n;
    temp = head;
    
    while(temp != NULL) {
        res--;
        if(res == 0) break;
        temp = temp->next;
    }
    
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int n = 3;
    ListNode* head = vectorToLL(v);
    head = removeNthFromEnd(head, n);
    print(head);
    return 0;
}