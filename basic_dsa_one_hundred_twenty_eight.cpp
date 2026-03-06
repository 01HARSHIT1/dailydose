/**
 * Basic DSA - Lowest Common Ancestor of Binary Tree (LeetCode 236)
 * Find lowest common ancestor of two nodes in a binary tree.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* L = lowestCommonAncestor(root->left, p, q);
    TreeNode* R = lowestCommonAncestor(root->right, p, q);
    if (L && R) return root;
    return L ? L : R;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lowest Common Ancestor of Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->right;
    std::cout << "LCA(5,1) -> " << lowestCommonAncestor(root, p, q)->val << "\n";

    TreeNode* q2 = root->left->right->right;
    std::cout << "LCA(5,4) -> " << lowestCommonAncestor(root, p, q2)->val << "\n";
}
