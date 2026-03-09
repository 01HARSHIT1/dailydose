/**
 * Basic DSA - Maximum Depth of Binary Tree (LeetCode 104)
 * Return the maximum depth (height) of a binary tree.
 */
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Depth of Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* a = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    std::cout << "[3,9,20,null,null,15,7] -> " << maxDepth(a) << "\n";

    TreeNode* b = new TreeNode(1, nullptr, new TreeNode(2));
    std::cout << "[1,null,2] -> " << maxDepth(b) << "\n";

    std::cout << "[] -> " << maxDepth(nullptr) << "\n";
}
