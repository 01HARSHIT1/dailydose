/**
 * Basic DSA - Distribute Elements Into Two Arrays I (LeetCode 3069)
 * Append each element to whichever array has the larger last value (arr1 on ties), then concatenate.
 */
#include <iostream>
#include <vector>

std::vector<int> resultArray(const std::vector<int>& nums) {
    std::vector<int> arr1{nums[0]};
    std::vector<int> arr2{nums[1]};
    for (size_t i = 2; i < nums.size(); ++i) {
        if (arr1.back() > arr2.back())
            arr1.push_back(nums[i]);
        else
            arr2.push_back(nums[i]);
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Distribute Elements Into Two Arrays I\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(resultArray({2, 1, 3, 3}));
    printVec(resultArray({5, 4, 3, 8}));
}
