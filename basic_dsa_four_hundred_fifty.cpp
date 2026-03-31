/**
 * Basic DSA - Find Lucky Integer in an Array (LeetCode 1394)
 * A lucky integer appears exactly as many times as its value; return the largest, or -1.
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int findLucky(std::vector<int>& arr) {
    std::unordered_map<int, int> cnt;
    for (int x : arr)
        ++cnt[x];
    int ans = -1;
    for (const auto& p : cnt) {
        if (p.first == p.second)
            ans = std::max(ans, p.first);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Lucky Integer in an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 2, 3, 4};
    std::cout << "[2,2,3,4] -> " << findLucky(a1) << "\n";

    std::vector<int> a2 = {1, 2, 2, 3, 3, 3};
    std::cout << "[1,2,2,3,3,3] -> " << findLucky(a2) << "\n";

    std::vector<int> a3 = {2, 2, 2, 3, 3};
    std::cout << "[2,2,2,3,3] -> " << findLucky(a3) << "\n";
}
