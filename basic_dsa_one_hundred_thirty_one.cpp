/**
 * Basic DSA - Kth Smallest Element in BST (LeetCode 230)
 * Find kth smallest element in BST (1-indexed).
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    int ans = 0, cnt = 0;
    auto inorder = [&](auto&& self, TreeNode* n) {
        if (!n) return;
        self(self, n->left);
        if (++cnt == k) { ans = n->val; return; }
        self(self, n->right);
    };
    inorder(inorder, root);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Kth Smallest Element in BST\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    std::cout << "[3,1,4,null,2], k=1 -> " << kthSmallest(root, 1) << "\n";
    std::cout << "[3,1,4,null,2], k=3 -> " << kthSmallest(root, 3) << "\n";
}
