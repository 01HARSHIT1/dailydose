/**
 * Basic DSA - Fixed Point (LeetCode 1064)
 * Strictly increasing integers; return smallest i with arr[i] == i, or -1.
 */
#include <iostream>
#include <string>
#include <vector>

int fixedPoint(const std::vector<int>& arr) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= mid) {
            if (arr[mid] == mid)
                ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fixed Point\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {-10, -5, 0, 3, 7};
    std::cout << "[-10,-5,0,3,7] -> " << fixedPoint(v1) << "\n";

    std::vector<int> v2 = {0, 2, 5, 8, 17};
    std::cout << "[0,2,5,8,17] -> " << fixedPoint(v2) << "\n";
}
