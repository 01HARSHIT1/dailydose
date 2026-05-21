/**
 * Basic DSA - Maximum Number of Integers to Choose From a Range I (LeetCode 2554)
 * Pick distinct integers from [1, n] not in banned; maximize how many we can choose.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

int maxCount(const std::vector<int>& banned, int n) {
    std::unordered_set<int> blocked(banned.begin(), banned.end());
    int count = 0;
    for (int value = 1; value <= n; ++value) {
        if (blocked.find(value) == blocked.end())
            ++count;
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Number of Integers to Choose From a Range I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxCount({1, 6, 5}, 5) << "\n";
    std::cout << "sample 2 -> " << maxCount({1, 2, 3, 4, 5, 6, 7}, 8) << "\n";
    std::cout << "sample 3 -> " << maxCount({11}, 7) << "\n";
}
