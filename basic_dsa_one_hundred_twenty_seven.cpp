/**
 * Basic DSA - Subtree of Another Tree (LeetCode 572)
 * Check if subRoot is a subtree of root.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Subtree of Another Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* sub = new TreeNode(4);
    sub->left = new TreeNode(1);
    sub->right = new TreeNode(2);

    std::cout << "[3,4,5,1,2] contains [4,1,2] -> " << (isSubtree(root, sub) ? "true" : "false") << "\n";

    sub->left->left = new TreeNode(0);
    std::cout << "[3,4,5,1,2] contains [4,1,2] (with 0) -> " << (isSubtree(root, sub) ? "true" : "false") << "\n";
}
