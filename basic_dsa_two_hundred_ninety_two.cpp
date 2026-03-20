/**
 * Basic DSA - Sum of Left Leaves (LeetCode 404)
 * Return sum of all left leaves in binary tree.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
    if (!root) return 0;
    if (!root->left && !root->right) return isLeft ? root->val : 0;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Left Leaves\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << "[3,9,20,null,15,7] -> " << sumOfLeftLeaves(root) << "\n";

    TreeNode* root2 = new TreeNode(1);
    std::cout << "[1] -> " << sumOfLeftLeaves(root2) << "\n";
}
