/**
 * Basic DSA - Maximum Subarray With Equal Products (LeetCode 3411)
 * Longest subarray where product equals gcd * lcm of its elements.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int gcdInt(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcmInt(int a, int b) {
    return a / gcdInt(a, b) * b;
}

int maxLength(const std::vector<int>& nums) {
    constexpr int kMaxProduct = 36288000;
    int best = 0;
    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i) {
        int product = 1;
        int g = 0;
        int l = 1;
        for (int j = i; j < n; ++j) {
            product *= nums[static_cast<size_t>(j)];
            if (product > kMaxProduct)
                break;
            g = gcdInt(g, nums[static_cast<size_t>(j)]);
            l = lcmInt(l, nums[static_cast<size_t>(j)]);
            if (product == g * l)
                best = std::max(best, j - i + 1);
        }
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Subarray With Equal Products\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxLength({1, 2, 1, 2, 1, 1, 1}) << "\n";
    std::cout << "sample 2 -> " << maxLength({2, 3, 4, 5, 6}) << "\n";
    std::cout << "sample 3 -> " << maxLength({1, 2, 3, 1, 4, 5, 1}) << "\n";
}
