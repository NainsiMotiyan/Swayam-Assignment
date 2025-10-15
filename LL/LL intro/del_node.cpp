#include <iostream>
using namespace std;

// Define a Node structure for the linked list
struct Node {
    int val;        // Value stored in the node
    Node* next;     // Pointer to the next node
    Node(int x) : val(x), next(nullptr) {}  // Constructor
};

// Function to insert a new node at the end of the list
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;  // If list is empty, new node becomes head
    Node* temp = head;
    while (temp->next) temp = temp->next;  // Traverse to last node
    temp->next = newNode;
    return head;
}

// Function to delete a node at a given position (1-based indexing)
Node* deleteAtPosition(Node* head, int pos) {
    if (!head) return nullptr;  // Empty list
    if (pos == 1) {             // Delete head node
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* temp = head;
    // Traverse to the node just before the position to delete
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp || !temp->next) return head;  // Position out of bounds
    Node* delNode = temp->next;
    temp->next = delNode->next;  // Remove the node from list
    delete delNode;              // Free memory
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test delete operation
int main() {
    Node* head = nullptr;

    // Insert nodes into the list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    cout << "Original Linked List: ";
    printList(head);

    // Delete node at position 2
    head = deleteAtPosition(head, 2);
    cout << "After deleting node at position 2: ";
    printList(head);

    // Delete node at position 1 (head)
    head = deleteAtPosition(head, 1);
    cout << "After deleting node at position 1: ";
    printList(head);

    // Delete node at position 5 (out of bounds)
    head = deleteAtPosition(head, 5);
    cout << "After trying to delete position 5: ";
    printList(head);

    return 0;
}
