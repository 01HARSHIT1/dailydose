/**
 * Basic DSA - Find Bottom Left Tree Value (LeetCode 513)
 * Return leftmost value in the last row of the tree.
 */
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findBottomLeftValue(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    int ans = root->val;
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front(); q.pop();
            if (i == 0) ans = cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Bottom Left Tree Value\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    std::cout << "[2,1,3] -> " << findBottomLeftValue(root) << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->right->left = new TreeNode(5);
    root2->right->left->left = new TreeNode(6);
    root2->right->left->right = new TreeNode(7);
    std::cout << "deeper tree -> " << findBottomLeftValue(root2) << "\n";
}
