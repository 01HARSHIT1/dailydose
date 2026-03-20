/**
 * Basic DSA - Lowest Common Ancestor of BST (LeetCode 235)
 * Return LCA of two nodes in BST.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lowest Common Ancestor of BST\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left, *q = root->right;
    std::cout << "LCA(2,8) -> " << lowestCommonAncestor(root, p, q)->val << "\n";

    p = root->left; q = root->left->right;
    std::cout << "LCA(2,4) -> " << lowestCommonAncestor(root, p, q)->val << "\n";
}
