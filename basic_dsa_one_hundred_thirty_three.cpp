/**
 * Basic DSA - Binary Tree Maximum Path Sum (LeetCode 124)
 * Find max path sum (path = any sequence of connected nodes).
 */
#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    auto dfs = [&](auto&& self, TreeNode* n) -> int {
        if (!n) return 0;
        int L = std::max(0, self(self, n->left));
        int R = std::max(0, self(self, n->right));
        ans = std::max(ans, n->val + L + R);
        return n->val + std::max(L, R);
    };
    dfs(dfs, root);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Tree Maximum Path Sum\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::cout << "[1,2,3] -> " << maxPathSum(root) << "\n";

    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    std::cout << "[-10,9,20,null,null,15,7] -> " << maxPathSum(root2) << "\n";
}
