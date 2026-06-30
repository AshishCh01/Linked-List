#include <iostream>
#include <unordered_set>
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
    // Create a map to store visited nodes
    unordered_set<ListNode*> visited;
    ListNode* temp = head;
    // Start traversing from head
    while (temp != NULL) {
        // If current node is already in set, it's the start of loop
        if (visited.find(temp) != visited.end()) {
            return temp;
        }

        // Otherwise, insert current node into set
        visited.insert(temp);

        // Move to the next node
        temp = temp->next;
    }

    // If loop not found, return NULL
    return NULL;
}

int main() {
    // Creating nodes
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating a cycle (tail connects to node index 1)
    head->next->next->next->next = head->next;

    ListNode* startNode = detectCycle(head);
    
    cout << startNode->val << endl;

    // if (startNode)
    //     cout << "Cycle starts at node with value: " << startNode->val << endl;
    // else
    //     cout << "No cycle found." << endl;

    return 0;
}