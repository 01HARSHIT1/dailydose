/**
 * Basic DSA - Validate BST (LeetCode 98)
 * Return true if tree is a valid BST.
 */
#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool check(TreeNode* root, long lo, long hi) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;
    return check(root->left, lo, root->val) && check(root->right, root->val, hi);
}

bool isValidBST(TreeNode* root) {
    return check(root, LONG_MIN, LONG_MAX);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Validate BST\n";
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
