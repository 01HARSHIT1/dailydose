/**
 * Basic DSA - Same Tree (LeetCode 100)
 * Return true if two binary trees are structurally identical.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Same Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);
    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);
    std::cout << "[1,2,3], [1,2,3] -> " << (isSameTree(p1, q1) ? "true" : "false") << "\n";

    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);
    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);
    std::cout << "[1,2], [1,null,2] -> " << (isSameTree(p2, q2) ? "true" : "false") << "\n";

    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);
    p3->right = new TreeNode(1);
    TreeNode* q3 = new TreeNode(1);
    q3->left = new TreeNode(1);
    q3->right = new TreeNode(2);
    std::cout << "[1,2,1], [1,1,2] -> " << (isSameTree(p3, q3) ? "true" : "false") << "\n";
}
