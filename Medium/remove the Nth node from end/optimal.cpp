#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int data, ListNode* next) {
        this->data = data;
        this->next = next;
    }

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
    // Create a dummy node before head to handle edge cases
    ListNode* dummy = new ListNode(0, head);

    // Initialize slow and fast pointers at dummy
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer N+1 steps ahead to create a gap
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Slow is now at node before target → delete target node
    slow->next = slow->next->next;

    // Return updated head
    return dummy->next;
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
