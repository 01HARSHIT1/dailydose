/**
 * Basic DSA - Validate Binary Search Tree (LeetCode 98)
 * Check if tree is a valid BST (left < root < right for all nodes).
 */
#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root) {
    auto check = [](auto&& self, TreeNode* n, long lo, long hi) -> bool {
        if (!n) return true;
        if (n->val <= lo || n->val >= hi) return false;
        return self(self, n->left, lo, n->val) && self(self, n->right, n->val, hi);
    };
    return check(check, root, LONG_MIN, LONG_MAX);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Validate Binary Search Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    std::cout << "[2,1,3] -> " << (isValidBST(root) ? "true" : "false") << "\n";

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    std::cout << "[5,1,4,null,null,3,6] -> " << (isValidBST(root2) ? "true" : "false") << "\n";
}
