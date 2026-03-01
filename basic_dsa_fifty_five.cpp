/**
 * Basic DSA - Insert into a BST (LeetCode 701)
 * Insert value into BST and return root.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

void inorder(TreeNode* n) {
    if (!n) return;
    inorder(n->left);
    std::cout << n->val << " ";
    inorder(n->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Insert into a Binary Search Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    insertIntoBST(root, 5);
    std::cout << "[4,2,7,1,3], val=5 -> inorder: ";
    inorder(root);
    std::cout << "\n";

    TreeNode* r2 = insertIntoBST(nullptr, 5);
    std::cout << "[], val=5 -> ";
    inorder(r2);
    std::cout << "\n";
}
