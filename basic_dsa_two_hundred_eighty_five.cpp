/**
 * Basic DSA - Symmetric Tree (LeetCode 101)
 * Return true if tree is mirror of itself.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool mirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    return !root || mirror(root->left, root->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Symmetric Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    std::cout << "[1,2,2,3,4,4,3] -> " << (isSymmetric(root) ? "true" : "false") << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);
    std::cout << "[1,2,2,null,3,null,3] -> " << (isSymmetric(root2) ? "true" : "false") << "\n";
}
