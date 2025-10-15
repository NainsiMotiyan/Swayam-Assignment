#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Function to insert node at the end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;  // Store next node
        curr->next = prev;  // Reverse current node's pointer
        prev = curr;        // Move prev to current node
        curr = next;        // Move to next node
    }

    return prev;  // New head of reversed list
}

// Function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Insert nodes
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
