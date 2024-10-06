#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper function to check if two trees are mirror images.
bool isMirror(TreeNode* leftTree, TreeNode* rightTree) {
    // If both nodes are null, they are mirror images
    if (!leftTree && !rightTree) return true;
    
    // If only one of them is null, they are not mirror images
    if (!leftTree || !rightTree) return false;
    
    // Check if current nodes are equal and if their subtrees are mirrors
    return (leftTree->val == rightTree->val) &&
           isMirror(leftTree->left, rightTree->right) &&
           isMirror(leftTree->right, rightTree->left);
}

// Main function to check if the tree is symmetric
bool isSymmetric(TreeNode* root) {
    // An empty tree is symmetric
    if (!root) return true;
    
    // Check if the left and right subtrees are mirror images
    return isMirror(root->left, root->right);
}

// Test cases
int main() {
    // Example 1: Input: [1, 2, 2, 3, 4, 4, 3]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root1->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    cout << (isSymmetric(root1) ? "true" : "false") << endl; // Output: true

    // Example 2: Input: [1, 2, 2, nullptr, 3, nullptr, 3]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2, nullptr, new TreeNode(3));
    root2->right = new TreeNode(2, nullptr, new TreeNode(3));
    cout << (isSymmetric(root2) ? "true" : "false") << endl; // Output: false

    // Example 3: Input: [1]
    TreeNode* root3 = new TreeNode(1);
    cout << (isSymmetric(root3) ? "true" : "false") << endl; // Output: true

    // Example 4: Input: []
    TreeNode* root4 = nullptr;
    cout << (isSymmetric(root4) ? "true" : "false") << endl; // Output: true

    // Example 5: Input: [1, 2, 2, 3, nullptr, nullptr, 3]
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2, new TreeNode(3), nullptr);
    root5->right = new TreeNode(2, nullptr, new TreeNode(3));
    cout << (isSymmetric(root5) ? "true" : "false") << endl; // Output: false

    return 0;
}
