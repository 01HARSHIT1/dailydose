/**
 * Basic DSA - Maximum Depth of Binary Tree (LeetCode 104)
 * Return maximum depth (number of nodes along longest path).
 */
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Depth of Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << "[3,9,20,null,15,7] -> " << maxDepth(root) << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    std::cout << "[1,null,2] -> " << maxDepth(root2) << "\n";
}
