/**
 * Basic DSA - Binary Search
 * Given a sorted array of distinct integers and a target, return its index, or -1 if absent.
 * Time: O(log n), Space: O(1).
 */
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& a, int target) {
    int lo = 0;
    int hi = static_cast<int>(a.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Search\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {1, 3, 5, 7, 9, 11};
    std::cout << "array: 1 3 5 7 9 11\n";
    std::cout << "target 7 -> index " << binarySearch(a, 7) << "\n";
    std::cout << "target 1 -> index " << binarySearch(a, 1) << "\n";
    std::cout << "target 11 -> index " << binarySearch(a, 11) << "\n";
    std::cout << "target 4 -> index " << binarySearch(a, 4) << "\n";
}
