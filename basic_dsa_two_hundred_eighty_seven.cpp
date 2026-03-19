/**
 * Basic DSA - Convert Sorted Array to BST (LeetCode 108)
 * Build height-balanced BST from sorted array.
 */
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(std::vector<int>& nums, int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = lo + (hi - lo) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, lo, mid - 1);
    root->right = build(nums, mid + 1, hi);
    return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return build(nums, 0, nums.size() - 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Convert Sorted Array to BST\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {-10, -3, 0, 5, 9};
    TreeNode* r1 = sortedArrayToBST(v1);
    std::cout << "[-10,-3,0,5,9] -> root=" << r1->val
              << " L=" << r1->left->val << " R=" << r1->right->val << "\n";

    std::vector<int> v2 = {1, 3};
    TreeNode* r2 = sortedArrayToBST(v2);
    std::cout << "[1,3] -> root=" << r2->val << "\n";
}
