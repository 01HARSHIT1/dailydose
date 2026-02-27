/**
 * Basic DSA - Binary Tree Level Order Traversal (LeetCode 102)
 * Return level-by-level traversal as list of lists.
 */
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> out;
    if (!root) return out;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        std::vector<int> level;
        for (int i = 0; i < sz; i++) {
            TreeNode* n = q.front();
            q.pop();
            level.push_back(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        out.push_back(level);
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Tree Level Order Traversal\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* a = new TreeNode(3);
    a->left = new TreeNode(9);
    a->right = new TreeNode(20);
    a->right->left = new TreeNode(15);
    a->right->right = new TreeNode(7);
    auto r = levelOrder(a);
    std::cout << "[3,9,20,null,null,15,7] -> [[3],[9,20],[15,7]]\n";
    std::cout << "Got: ";
    for (auto& row : r) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            std::cout << row[i];
            if (i + 1 < row.size()) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n";
}
