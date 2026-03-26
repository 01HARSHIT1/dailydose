/**
 * Basic DSA - H-Index II (LeetCode 275)
 * Citations sorted ascending; compute h-index in O(log n).
 */
#include <iostream>
#include <string>
#include <vector>

int hIndex(std::vector<int>& citations) {
    int n = static_cast<int>(citations.size());
    int lo = 0;
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (citations[n - mid] >= mid)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: H-Index II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {0, 1, 3, 5, 6};
    std::cout << "[0,1,3,5,6] -> " << hIndex(v1) << "\n";

    std::vector<int> v2 = {1, 2, 100};
    std::cout << "[1,2,100] -> " << hIndex(v2) << "\n";
}
