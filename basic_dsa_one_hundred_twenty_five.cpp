/**
 * Basic DSA - Diameter of Binary Tree (LeetCode 543)
 * Longest path between any two nodes (may not pass through root).
 */
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    auto dfs = [&](auto&& self, TreeNode* n) -> int {
        if (!n) return 0;
        int L = self(self, n->left);
        int R = self(self, n->right);
        ans = std::max(ans, L + R);
        return 1 + std::max(L, R);
    };
    dfs(dfs, root);
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
