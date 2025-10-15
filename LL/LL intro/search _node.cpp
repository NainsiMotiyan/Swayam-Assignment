#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Function to insert a node at the end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to search for a node by value
int searchNode(Node* head, int key) {
    int position = 1; // Positions are 1-based
    while (head) {
        if (head->val == key)
            return position; // Node found
        head = head->next;
        position++;
    }
    return -1; // Node not found
}

// Function to print the linked list
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

    // Insert sample nodes
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    cout << "Linked List: ";
    printList(head);

    int key = 20;
    int pos = searchNode(head, key);
    if (pos != -1)
        cout << "Node " << key << " found at position: " << pos << endl;
    else
        cout << "Node " << key << " not found in the list." << endl;

    return 0;
}
