/**
 * Basic DSA - Final Array State After K Multiplication Operations I (LeetCode 3264)
 * Repeatedly multiply the smallest element (smallest index on ties) by multiplier.
 */
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> getFinalState(std::vector<int> nums, int k, int multiplier) {
    using Entry = std::pair<int, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> heap;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        heap.push({nums[static_cast<size_t>(i)], i});

    for (int op = 0; op < k; ++op) {
        Entry top = heap.top();
        heap.pop();
        int idx = top.second;
        nums[static_cast<size_t>(idx)] *= multiplier;
        heap.push({nums[static_cast<size_t>(idx)], idx});
    }
    return nums;
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
    std::cout << "Problem: Final Array State After K Multiplication Operations I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printArray(getFinalState({2, 1, 3, 5, 6}, 5, 2));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printArray(getFinalState({1, 2}, 3, 4));
    std::cout << "\n";
}
