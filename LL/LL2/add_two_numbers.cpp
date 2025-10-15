#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }

        return dummyNode->next;
    }
};

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    for (int n : nums) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Input 1: ";
    printList(l1);
    cout << "Input 2: ";
    printList(l2);
    cout << "Sum:     ";
    printList(result);

    return 0;
}
