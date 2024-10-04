#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

private:
    bool isValidBST(TreeNode* node, int minVal, int maxVal) {
        // An empty node is a valid BST
        if (node == nullptr) {
            return true;
        }

        // The current node's value must be within the valid range
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // Check the left subtree and right subtree with updated ranges
        return isValidBST(node->left, minVal, node->val) &&
               isValidBST(node->right, node->val, maxVal);
    }
};

// Helper function to create a tree from a given array representation
TreeNode* createTree(int arr[], int n) {
    if (n == 0) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    TreeNode* nodes[n];
    nodes[0] = root;

    for (int i = 1; i < n; ++i) {
        if (arr[i] != NULL) {
            TreeNode* newNode = new TreeNode(arr[i]);
            nodes[i] = newNode;

            if (i % 2 == 1) {
                nodes[(i - 1) / 2]->left = newNode;
            } else {
                nodes[(i - 2) / 2]->right = newNode;
            }
        } else {
            nodes[i] = nullptr;
        }
    }
    return root;
}

int main() {
    // Input: root = [2, 1, 3]
    int arr[] = {2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = createTree(arr, n);
    Solution solution;
    bool result = solution.isValidBST(root);

    std::cout << (result ? "true" : "false") << std::endl;

    // Clean up memory (not shown for brevity)
    return 0;
}
