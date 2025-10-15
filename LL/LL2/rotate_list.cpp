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

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Rotate linked list to the right by k positions
Node* rotateList(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find length and last node
    Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }

    k %= length;        // If k >= length
    if (k == 0) return head;

    temp->next = head;  // Make it circular
    Node* newTail = head;
    for (int i = 0; i < length - k - 1; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = nullptr; // Break circular link

    return newHead;
}

// Main function
int main() {
    Node* head = nullptr;

    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 1; i <= 5; i++)
        head = insertAtEnd(head, i);

    cout << "Original List: ";
    printList(head);

    head = rotateList(head, 2); // Rotate by 2
    cout << "After Rotating by 2: ";
    printList(head);

    return 0;
}
