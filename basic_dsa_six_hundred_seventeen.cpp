/**
 * Basic DSA - Count Number of Beautiful Subsets (LeetCode 2549)
 * Backtrack subsets where no two chosen values differ by k; track used values in a frequency map.
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

int beautifulSubsets(const std::vector<int>& nums, int k) {
    std::vector<int> sorted = nums;
    std::sort(sorted.begin(), sorted.end());
    std::unordered_map<int, int> used;

    std::function<long long(int)> countFrom = [&](int index) -> long long {
        if (index == static_cast<int>(sorted.size()))
            return 1;

        long long ways = countFrom(index + 1);
        int value = sorted[static_cast<size_t>(index)];
        if (used[value - k] == 0 && used[value + k] == 0) {
            ++used[value];
            ways += countFrom(index + 1);
            if (--used[value] == 0)
                used.erase(value);
        }
        return ways;
    };

    return static_cast<int>(countFrom(0) - 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Number of Beautiful Subsets\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << beautifulSubsets({2, 4, 6}, 2) << "\n";
    std::cout << "sample 2 -> " << beautifulSubsets({1}, 1) << "\n";
}
