/**
 * Basic DSA - Find Indices of Stable Mountains (LeetCode 3285)
 * Index i is stable when the previous mountain height is strictly greater than threshold.
 */
#include <iostream>
#include <vector>

std::vector<int> stableMountains(const std::vector<int>& height, int threshold) {
    std::vector<int> result;
    for (int i = 1; i < static_cast<int>(height.size()); ++i) {
        if (height[static_cast<size_t>(i - 1)] > threshold)
            result.push_back(i);
    }
    return result;
}

void printArray(const std::vector<int>& nums) {
    std::cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << nums[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Indices of Stable Mountains\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printArray(stableMountains({1, 2, 3, 4, 5}, 2));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printArray(stableMountains({10, 1, 10, 1, 10}, 3));
    std::cout << "\n";

    std::cout << "sample 3 -> ";
    printArray(stableMountains({10, 1, 10, 1, 10}, 10));
    std::cout << "\n";
}
