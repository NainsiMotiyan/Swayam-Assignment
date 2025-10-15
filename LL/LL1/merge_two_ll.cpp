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

// Merge two sorted linked lists
Node* mergeSorted(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
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
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    // Sorted list 1
    l1 = insertAtEnd(l1, 1);
    l1 = insertAtEnd(l1, 3);
    l1 = insertAtEnd(l1, 5);

    // Sorted list 2
    l2 = insertAtEnd(l2, 2);
    l2 = insertAtEnd(l2, 4);
    l2 = insertAtEnd(l2, 6);

    cout << "List1: "; printList(l1);
    cout << "List2: "; printList(l2);

    Node* merged = mergeSorted(l1, l2);
    cout << "Merged List: "; printList(merged);

    return 0;
}
