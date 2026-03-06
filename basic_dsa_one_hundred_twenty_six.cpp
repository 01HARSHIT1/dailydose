/**
 * Basic DSA - Balanced Binary Tree (LeetCode 110)
 * Check if tree is height-balanced (|left - right| <= 1 for every node).
 */
#include <iostream>
#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBalanced(TreeNode* root) {
    auto check = [](auto&& self, TreeNode* n) -> int {
        if (!n) return 0;
        int L = self(self, n->left);
        int R = self(self, n->right);
        if (L == -1 || R == -1 || std::abs(L - R) > 1) return -1;
        return 1 + std::max(L, R);
    };
    return check(check, root) != -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Balanced Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << "[3,9,20,null,null,15,7] -> " << (isBalanced(root) ? "true" : "false") << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);
    root2->right->right->right = new TreeNode(4);
    std::cout << "[1,2,2,3,null,null,3,4,null,null,4] -> " << (isBalanced(root2) ? "true" : "false") << "\n";
}
