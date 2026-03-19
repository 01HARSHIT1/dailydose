/**
 * Basic DSA - Merge Two Binary Trees (LeetCode 617)
 * Merge trees: sum overlapping nodes, keep non-overlapping.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Two Binary Trees\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* r1 = new TreeNode(1);
    r1->left = new TreeNode(3);
    r1->right = new TreeNode(2);
    r1->left->left = new TreeNode(5);

    TreeNode* r2 = new TreeNode(2);
    r2->left = new TreeNode(1);
    r2->right = new TreeNode(3);
    r2->left->right = new TreeNode(4);
    r2->right->right = new TreeNode(7);

    mergeTrees(r1, r2);
    std::cout << "Merge [1,3,2,5] & [2,1,3,null,4,null,7] -> root=" << r1->val
              << " L=" << r1->left->val << " R=" << r1->right->val << "\n";
}
