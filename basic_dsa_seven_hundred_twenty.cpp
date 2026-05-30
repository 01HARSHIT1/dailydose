/**
 * Basic DSA - Apply Operations to Make Sum of Array Greater Than or Equal to k (LeetCode 3091)
 * Start with [1]; increment then duplicate. Minimize ops so sum >= k.
 */
#include <algorithm>
#include <iostream>

int minOperations(int k) {
    int ans = k;
    for (int inc = 0; inc < k; ++inc) {
        int value = inc + 1;
        int dup = (k + value - 1) / value - 1;
        ans = std::min(ans, inc + dup);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Apply Operations to Make Sum of Array >= k\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minOperations(11) << "\n";
    std::cout << "sample 2 -> " << minOperations(1) << "\n";
}
