/**
 * Basic DSA - Serialize and Deserialize Binary Tree (LeetCode 297)
 * Encode tree to string and decode back to tree.
 */
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    std::string serialize(TreeNode* root) {
        if (!root) return "null";
        return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(std::string data) {
        std::stringstream ss(data);
        return build(ss);
    }
private:
    TreeNode* build(std::stringstream& ss) {
        std::string s;
        if (!getline(ss, s, ',') || s == "null") return nullptr;
        TreeNode* n = new TreeNode(stoi(s));
        n->left = build(ss);
        n->right = build(ss);
        return n;
    }
};

void printInorder(TreeNode* n) {
    if (!n) return;
    printInorder(n->left);
    std::cout << n->val << " ";
    printInorder(n->right);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Serialize and Deserialize Binary Tree\n";
    std::cout << std::string(60, '=') << "\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec c;
    std::string enc = c.serialize(root);
    std::cout << "Encoded: " << enc << "\n";

    TreeNode* dec = c.deserialize(enc);
    std::cout << "Decoded inorder: ";
    printInorder(dec);
    std::cout << "\n";
}
