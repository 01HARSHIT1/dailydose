/**
 * Basic DSA - Binary Tree Level Order Traversal (LeetCode 102)
 * Return level-order (BFS) traversal as list of levels.
 */
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (!root) return ans;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        std::vector<int> level;
        for (int i = 0; i < sz; i++) {
            TreeNode* n = q.front(); q.pop();
            level.push_back(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        ans.push_back(level);
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

    auto levels = levelOrder(root);
    std::cout << "[3,9,20,null,null,15,7] -> ";
    for (auto& lev : levels) {
        std::cout << "[";
        for (size_t i = 0; i < lev.size(); i++)
            std::cout << (i ? "," : "") << lev[i];
        std::cout << "] ";
    }
    std::cout << "\n";
}
