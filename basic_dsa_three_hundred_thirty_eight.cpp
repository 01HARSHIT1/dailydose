/**
 * Basic DSA - Next Greater Element I (LeetCode 496)
 * For each nums1[i], next greater in nums2 (right), or -1.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> nxt;
    std::stack<int> st;
    for (int x : nums2) {
        while (!st.empty() && st.top() < x) {
            nxt[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }
    std::vector<int> ans;
    for (int x : nums1) ans.push_back(nxt.count(x) ? nxt[x] : -1);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Next Greater Element I\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {4, 1, 2}, b1 = {1, 3, 4, 2};
    auto r1 = nextGreaterElement(a1, b1);
    std::cout << "nums1=[4,1,2] -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {2, 4}, b2 = {1, 2, 3, 4};
    auto r2 = nextGreaterElement(a2, b2);
    std::cout << "nums1=[2,4] -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
