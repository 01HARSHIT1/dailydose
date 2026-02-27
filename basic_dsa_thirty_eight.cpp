/**
 * Basic DSA - Diameter of Binary Tree (LeetCode 543)
 * Return the length of the longest path between any two nodes.
 */
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameterOfBinaryTree(TreeNode* root) {
    int best = 0;
    auto dfs = [&](auto self, TreeNode* n) -> int {
        if (!n) return 0;
        int L = self(self, n->left);
        int R = self(self, n->right);
        best = std::max(best, L + R);
        return 1 + std::max(L, R);
    };
    dfs(dfs, root);
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Diameter of Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    a->left->left = new TreeNode(4);
    a->left->right = new TreeNode(5);
    std::cout << "[1,2,3,4,5] -> " << diameterOfBinaryTree(a) << "\n";

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    std::cout << "[1,2] -> " << diameterOfBinaryTree(b) << "\n";
}
