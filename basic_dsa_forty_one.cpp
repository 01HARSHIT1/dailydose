/**
 * Basic DSA - Balanced Binary Tree (LeetCode 110)
 * Check if tree is height-balanced (|left height - right height| <= 1 at every node).
 * Made with Cursor
 */
#include <iostream>
#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBalanced(TreeNode* root) {
    auto check = [](auto self, TreeNode* n) -> int {
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

    TreeNode* a = new TreeNode(3);
    a->left = new TreeNode(9);
    a->right = new TreeNode(20);
    a->right->left = new TreeNode(15);
    a->right->right = new TreeNode(7);
    std::cout << "[3,9,20,null,null,15,7] -> " << (isBalanced(a) ? "true" : "false") << "\n";

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->left->left = new TreeNode(3);
    b->right = new TreeNode(2);
    std::cout << "[1,2,2,3,null,null,3,4,null,null,4] -> " << (isBalanced(b) ? "true" : "false") << "\n";

    std::cout << "[] -> " << (isBalanced(nullptr) ? "true" : "false") << "\n";
}
