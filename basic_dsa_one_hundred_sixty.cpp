/**
 * Basic DSA - Symmetric Tree (LeetCode 101)
 * Check if binary tree is mirror of itself.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

bool isMirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b || a->val != b->val) return false;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    return !root || isMirror(root->left, root->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Symmetric Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* a = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    std::cout << "[1,2,2,3,4,4,3] -> " << (isSymmetric(a) ? "true" : "false") << "\n";

    TreeNode* b = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(3)),
        new TreeNode(2, nullptr, new TreeNode(3)));
    std::cout << "[1,2,2,null,3,null,3] -> " << (isSymmetric(b) ? "true" : "false") << "\n";

    std::cout << "[] -> " << (isSymmetric(nullptr) ? "true" : "false") << "\n";
}
