#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Morris Inorder Traversal (no recursion, no stack)
void morrisTraversal(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Morris Inorder Traversal: ";
    morrisTraversal(root);
    cout << endl;
}
