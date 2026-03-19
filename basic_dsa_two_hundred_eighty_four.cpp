/**
 * Basic DSA - Path Sum (LeetCode 112)
 * Return true if tree has root-to-leaf path with sum = targetSum.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == targetSum;
    int rem = targetSum - root->val;
    return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Path Sum\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    std::cout << "[5,4,8,11,null,13,4,7,2,null,null,null,1], 22 -> "
              << (hasPathSum(root, 22) ? "true" : "false") << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    std::cout << "[1,2,3], 5 -> " << (hasPathSum(root2, 5) ? "true" : "false") << "\n";
}
