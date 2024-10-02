#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or we find either p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Recur for left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right return non-null, current node is LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Otherwise, return non-null node (either left or right) or null if neither
        return (left != nullptr) ? left : right;
    }
};

int main() {
    // Example tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;

    // Test Case 1
    TreeNode* p = root->left; // node 5
    TreeNode* q = root->right; // node 1
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 1 is: " << lca->val << endl; // Output should be 3

    // Test Case 2
    p = root->left; // node 5
    q = root->left->right->right; // node 4
    lca = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 4 is: " << lca->val << endl; // Output should be 5

    return 0;
}
