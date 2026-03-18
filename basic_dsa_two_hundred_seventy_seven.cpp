/**
 * Basic DSA - Average of Levels in Binary Tree (LeetCode 637)
 * Return average of values at each level.
 */
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> ans;
    if (!root) return ans;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        long sum = 0;
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front(); q.pop();
            sum += cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ans.push_back((double)sum / n);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Average of Levels in Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto r = averageOfLevels(root);
    std::cout << "[3,9,20,null,15,7] -> [";
    for (int i = 0; i < (int)r.size(); i++) std::cout << (i ? "," : "") << r[i];
    std::cout << "]\n";
}
