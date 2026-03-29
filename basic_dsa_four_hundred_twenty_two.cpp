/**
 * Basic DSA - Element Appearing More Than 25% In Sorted Array (LeetCode 1287)
 * Exactly one value appears more than n/4 times; array is non-decreasing.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int findSpecialInteger(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int pos : {0, n / 4, n / 2, 3 * n / 4}) {
        int x = arr[static_cast<size_t>(pos)];
        auto lo = std::lower_bound(arr.begin(), arr.end(), x);
        auto hi = std::upper_bound(arr.begin(), arr.end(), x);
        if (hi - lo > n / 4)
            return x;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Element Appearing More Than 25% In Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    std::cout << "[1,2,2,6,6,6,6,7,10] -> " << findSpecialInteger(v1) << "\n";

    std::vector<int> v2 = {1, 1};
    std::cout << "[1,1] -> " << findSpecialInteger(v2) << "\n";
}
