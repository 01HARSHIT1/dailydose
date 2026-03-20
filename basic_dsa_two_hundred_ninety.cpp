/**
 * Basic DSA - Subtree of Another Tree (LeetCode 572)
 * Return true if subRoot is a subtree of root.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool same(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && same(a->left, b->left) && same(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    return same(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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

    std::cout << "[3,4,5,1,2] vs [4,1,2] -> "
              << (isSubtree(root, sub) ? "true" : "false") << "\n";

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    root2->left->right->left = new TreeNode(0);
    std::cout << "[3,4,5,1,2,null,null,null,null,0] vs [4,1,2] -> "
              << (isSubtree(root2, sub) ? "true" : "false") << "\n";
}
