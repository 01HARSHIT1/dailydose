/**
 * Basic DSA - Construct Binary Tree from Preorder and Inorder (LeetCode 105)
 * Build tree from preorder and inorder traversal arrays.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(std::vector<int>& pre, std::vector<int>& in) {
    std::unordered_map<int, int> pos;
    for (int i = 0; i < (int)in.size(); i++) pos[in[i]] = i;
    int idx = 0;
    auto build = [&](auto&& self, int lo, int hi) -> TreeNode* {
        if (lo > hi) return nullptr;
        int v = pre[idx++];
        TreeNode* n = new TreeNode(v);
        int m = pos[v];
        n->left = self(self, lo, m - 1);
        n->right = self(self, m + 1, hi);
        return n;
    };
    return build(build, 0, in.size() - 1);
}

void printInorder(TreeNode* n) {
    if (!n) return;
    printInorder(n->left);
    std::cout << n->val << " ";
    printInorder(n->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Construct Binary Tree from Preorder and Inorder\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> in = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(pre, in);
    std::cout << "pre=[3,9,20,15,7], in=[9,3,15,20,7] -> inorder: ";
    printInorder(root);
    std::cout << "\n";
}
