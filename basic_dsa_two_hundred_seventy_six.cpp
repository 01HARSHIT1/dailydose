/**
 * Basic DSA - Peak Index in a Mountain Array (LeetCode 852)
 * Return index of peak in mountain array.
 */
#include <iostream>
#include <vector>

int peakIndexInMountainArray(std::vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < arr[mid + 1]) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Peak Index in a Mountain Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {0, 1, 0};
    std::cout << "[0,1,0] -> " << peakIndexInMountainArray(v1) << "\n";

    std::vector<int> v2 = {0, 2, 1, 0};
    std::cout << "[0,2,1,0] -> " << peakIndexInMountainArray(v2) << "\n";

    std::vector<int> v3 = {0, 10, 5, 2};
    std::cout << "[0,10,5,2] -> " << peakIndexInMountainArray(v3) << "\n";
}
