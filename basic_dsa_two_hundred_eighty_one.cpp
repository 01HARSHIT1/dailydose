/**
 * Basic DSA - Diameter of Binary Tree (LeetCode 543)
 * Return length of longest path between any two nodes.
 */
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;
int depth(TreeNode* root) {
    if (!root) return 0;
    int L = depth(root->left);
    int R = depth(root->right);
    ans = std::max(ans, L + R);
    return 1 + std::max(L, R);
}

int diameterOfBinaryTree(TreeNode* root) {
    ans = 0;
    depth(root);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Diameter of Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "[1,2,3,4,5] -> " << diameterOfBinaryTree(root) << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    std::cout << "[1,2] -> " << diameterOfBinaryTree(root2) << "\n";
}
