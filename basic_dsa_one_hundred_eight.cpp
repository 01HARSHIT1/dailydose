/**
 * Basic DSA - Product of Array Except Self (LeetCode 238)
 * Return array where output[i] = product of all elements except nums[i].
 */
#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> ans(n, 1);
    int pre = 1, suf = 1;
    for (int i = 0; i < n; i++) {
        ans[i] *= pre;
        pre *= nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suf;
        suf *= nums[i];
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Product of Array Except Self\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4};
    auto r1 = productExceptSelf(a1);
    std::cout << "[1,2,3,4] -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {-1, 1, 0, -3, 3};
    auto r2 = productExceptSelf(a2);
    std::cout << "[-1,1,0,-3,3] -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
