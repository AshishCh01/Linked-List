#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


ListNode* detectCycle(ListNode* head) {
    // Initialize slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse until fast and fast->next are not null
    while (fast != NULL && fast->next != NULL) {
        // Move slow by one step
        slow = slow->next;

        // Move fast by two steps
        fast = fast->next->next;

        // If they meet, loop is detected
        if (slow == fast) {
            // Reset slow to head
            slow = head;

            // Move both one step at a time to find starting point
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            // Return the start node of the loop
            return slow;
        }
    }

    // If no loop found, return NULL
    return NULL;
}


int main()
{
    // Create nodes
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create a cycle: connect tail to index 1 node (value 2)
    head->next->next->next->next = head->next;

    
    ListNode* result = detectCycle(head);
    cout << result->val << endl;
    // OR
    if (result != NULL)
        cout << "Cycle starts at node with value: " << result->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}