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

// Remove duplicates from a sorted linked list
Node* removeDuplicates(Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            Node* dup = current->next;
            current->next = current->next->next;
            delete dup;
        } else {
            current = current->next;
        }
    }
    return head;
}

// Main function
int main() {
    Node* head = nullptr;

    // Sorted list: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);
    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
