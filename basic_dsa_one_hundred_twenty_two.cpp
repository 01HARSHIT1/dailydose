/**
 * Basic DSA - Same Tree (LeetCode 100)
 * Check if two binary trees are structurally identical.
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

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Same Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    std::cout << "[1,2,3] vs [1,2,3] -> " << (isSameTree(p, q) ? "true" : "false") << "\n";

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    std::cout << "[1,2,3] vs [1,2] -> " << (isSameTree(p, r) ? "true" : "false") << "\n";
}
