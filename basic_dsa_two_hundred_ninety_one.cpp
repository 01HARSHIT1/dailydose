/**
 * Basic DSA - Binary Tree Paths (LeetCode 257)
 * Return all root-to-leaf paths as "a->b->c" strings.
 */
#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* root, std::string path, std::vector<std::string>& ans) {
    if (!root) return;
    path += (path.empty() ? "" : "->") + std::to_string(root->val);
    if (!root->left && !root->right) {
        ans.push_back(path);
        return;
    }
    dfs(root->left, path, ans);
    dfs(root->right, path, ans);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> ans;
    dfs(root, "", ans);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Tree Paths\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    auto r = binaryTreePaths(root);
    for (const std::string& s : r) std::cout << s << "\n";

    TreeNode* root2 = new TreeNode(1);
    auto r2 = binaryTreePaths(root2);
    std::cout << "single node: " << r2[0] << "\n";
}
