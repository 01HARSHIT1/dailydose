/**
 * Basic DSA - Binary Tree Inorder Traversal (LeetCode 94)
 * Return inorder traversal (left, root, right) of binary tree.
 */
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, std::vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> out;
    inorder(root, out);
    return out;
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Tree Inorder Traversal\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* a = new TreeNode(1);
    a->right = new TreeNode(2);
    a->right->left = new TreeNode(3);
    auto r1 = inorderTraversal(a);
    std::cout << "[1,null,2,3] -> ";
    print(r1);

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);
    auto r2 = inorderTraversal(b);
    std::cout << "[1,2,3] -> ";
    print(r2);
}
