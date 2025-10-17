#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes; // Map value -> TreeNode pointer
        unordered_set<int> childSet;         // Track all child nodes

        // Step 1: Build tree connections
        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            // Create parent and child if not already created
            if (!nodes[parent]) nodes[parent] = new TreeNode(parent);
            if (!nodes[child]) nodes[child] = new TreeNode(child);

            // Connect parent-child based on isLeft flag
            if (isLeft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            // Mark this node as a child
            childSet.insert(child);
        }

        // Step 2: Find the root (the node that was never a child)
        TreeNode* root = nullptr;
        for (auto& desc : descriptions) {
            int parent = desc[0];
            if (childSet.find(parent) == childSet.end()) {
                root = nodes[parent];
                break;
            }
        }

        return root;
    }
};

// -------- Example usage --------
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}
    };

    Solution obj;
    TreeNode* root = obj.createBinaryTree(descriptions);

    cout << "Preorder Traversal of Constructed Tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
