#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* arrayToLL(int arr[], int n) {

    // Empty array
    if (n == 0)
        return NULL;

    // First node
    Node* head = new Node(arr[0]);
    Node* tail = head;

    // Remaining nodes
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }

    return head;
}


Node* middleNode(Node* head) {
    Node* temp = head;
    int cnt = 0;
    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    
    // Calculate the position of the middle node
    int midNode= cnt / 2 + 1;
    temp = head;
    
    // Traverse to the middle node by moving temp to the middle position.
    while(temp != NULL) {
        midNode = midNode - 1;
        
        // Check if the middle position is reached
        if(midNode == 0) {   // break out of the loop to return temp
            break;
        }
        // move ahead of the temp
        temp = temp->next;
    }
    return temp;
}

int main()
{
    int arr[] = {12,5,6,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToLL(arr, n);
    Node* mid = middleNode(head);

    cout << mid->data;
    return 0;
}