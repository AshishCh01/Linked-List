// Tortoise and heir algorithm
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

Node* deleteMiddle(Node* head) {
    // Initialize a temporary node to traverse the linked list
    Node* temp = head;
    int cnt = 0;
    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    
    // Calculate the position of the middle node
    int midNode= cnt / 2;
    temp = head;
    
    // Loop to find the middle node to delete
    // while (temp != NULL) {
    //     midNode--;
    //     if(midNode == 0) {   // If the middle node is found
    //         Node* middle = temp->next;   // Create a pointer to the middle node
    //         temp->next = temp->next->next;   // Adjust pointers to skip the middle node
    //         delete(middle);  // Free the memory allocated to the middle node
    //         break;   // Exit the loop after deleting the middle node
    //     }
        
    //     temp = temp->next;
    // }
    // OR
    for(int i = 0; i < midNode - 1; i++) {
            temp = temp->next;
    }
    Node* middle = temp->next;
    temp->next = middle->next;
    delete middle;
    
    return head;
}

// print LL
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int arr[] = {12,5,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = arrayToLL(arr, n);
    Node* mid = deleteMiddle(head);
    print(head);
    //cout << mid->data;

    return 0;
}