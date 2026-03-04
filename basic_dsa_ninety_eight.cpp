/**
 * Basic DSA - Create Target Array in Given Order (LeetCode 1389)
 * Build target: nums[i] at index[i]; insert at index (shift existing right).
 */
#include <iostream>
#include <vector>

std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> target;
    for (size_t i = 0; i < nums.size(); i++) {
        target.insert(target.begin() + index[i], nums[i]);
    }
    return target;
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
    std::cout << "Problem: Create Target Array in Given Order\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> n1 = {0, 1, 2, 3, 4};
    std::vector<int> i1 = {0, 1, 2, 2, 1};
    auto r1 = createTargetArray(n1, i1);
    std::cout << "nums=[0,1,2,3,4], index=[0,1,2,2,1] -> ";
    print(r1);

    std::vector<int> n2 = {1, 2, 3, 4, 0};
    std::vector<int> i2 = {0, 1, 2, 3, 0};
    auto r2 = createTargetArray(n2, i2);
    std::cout << "nums=[1,2,3,4,0], index=[0,1,2,3,0] -> ";
    print(r2);
}
