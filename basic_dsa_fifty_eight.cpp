/**
 * Basic DSA - Product of Array Except Self (LeetCode 238)
 * Return array where output[i] = product of all elements except nums[i].
 */
#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = (int)nums.size();
    std::vector<int> out(n, 1);
    int pre = 1, suf = 1;
    for (int i = 0; i < n; i++) {
        out[i] *= pre;
        pre *= nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        out[i] *= suf;
        suf *= nums[i];
    }
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
    std::cout << "Problem: Product of Array Except Self\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4};
    auto r1 = productExceptSelf(a1);
    std::cout << "[1,2,3,4] -> ";
    print(r1);

    std::vector<int> a2 = {-1, 1, 0, -3, 3};
    auto r2 = productExceptSelf(a2);
    std::cout << "[-1,1,0,-3,3] -> ";
    print(r2);
}
