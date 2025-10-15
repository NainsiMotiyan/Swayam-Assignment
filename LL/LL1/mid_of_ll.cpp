#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Insert node at end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to find the middle node
Node* findMiddle(Node* head) {
    if (!head) return nullptr;
    Node* slow = head;  // Moves one step at a time
    Node* fast = head;  // Moves two steps at a time

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  // slow points to middle
}

// Print list
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
    head = insertAtEnd(head, 5);

    cout << "Linked List: ";
    printList(head);

    Node* mid = findMiddle(head);
    if (mid) cout << "Middle Node Value: " << mid->val << endl;

    return 0;
}
