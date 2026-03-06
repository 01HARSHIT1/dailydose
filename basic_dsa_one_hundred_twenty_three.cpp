/**
 * Basic DSA - Invert Binary Tree (LeetCode 226)
 * Invert the tree (swap left and right subtrees).
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}

void printInorder(TreeNode* n) {
    if (!n) return;
    printInorder(n->left);
    std::cout << n->val << " ";
    printInorder(n->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Invert Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    invertTree(root);
    std::cout << "[4,2,7,1,3,6,9] inverted inorder -> ";
    printInorder(root);
    std::cout << "\n";
}
