#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Insert at given position (1-based)
Node* insertAtPosition(Node* head, int pos, int val) {
    Node* newNode = new Node(val);
    if (pos == 1) { // insert at head
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    for (int i = 1; i < pos-1 && temp; i++)
        temp = temp->next;

    if (!temp) return head; // position out of bounds

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    head = insertAtPosition(head, 1, 10);
    head = insertAtPosition(head, 2, 20);
    head = insertAtPosition(head, 2, 15);
    printList(head); // 10 -> 15 -> 20 -> NULL
    return 0;
}
