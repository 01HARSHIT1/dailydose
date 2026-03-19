/**
 * Basic DSA - Binary Tree Level Order Traversal (LeetCode 102)
 * Return level-order traversal as list of lists.
 */
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (!root) return ans;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        std::vector<int> row;
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front(); q.pop();
            row.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ans.push_back(row);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Tree Level Order Traversal\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto r = levelOrder(root);
    std::cout << "[3,9,20,null,15,7] -> [[3],[9,20],[15,7]]\n";
    std::cout << "Output: ";
    for (auto& row : r) {
        std::cout << "[";
        for (int i = 0; i < (int)row.size(); i++) std::cout << (i ? "," : "") << row[i];
        std::cout << "] ";
    }
    std::cout << "\n";
}
