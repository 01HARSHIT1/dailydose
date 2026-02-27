/**
 * Basic DSA - Invert Binary Tree (LeetCode 226)
 * Swap left and right children of every node.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* t = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(t);
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

    TreeNode* a = new TreeNode(4);
    a->left = new TreeNode(2);
    a->right = new TreeNode(7);
    a->left->left = new TreeNode(1);
    a->left->right = new TreeNode(3);
    a->right->left = new TreeNode(6);
    a->right->right = new TreeNode(9);
    invertTree(a);
    std::cout << "[4,2,7,1,3,6,9] inverted inorder -> ";
    printInorder(a);
    std::cout << "\n";

    TreeNode* b = new TreeNode(2);
    b->left = new TreeNode(1);
    b->right = new TreeNode(3);
    invertTree(b);
    std::cout << "[2,1,3] inverted inorder -> ";
    printInorder(b);
    std::cout << "\n";
}
