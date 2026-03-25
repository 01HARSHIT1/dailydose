/**
 * Basic DSA - Degree of an Array (LeetCode 697)
 * Degree is max frequency; return shortest subarray with the same degree.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int findShortestSubArray(std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    std::unordered_map<int, int> first;
    std::unordered_map<int, int> last;
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        if (first.find(x) == first.end())
            first[x] = i;
        last[x] = i;
        ++count[x];
    }
    int deg = 0;
    for (const auto& p : count)
        deg = std::max(deg, p.second);
    int ans = n;
    for (const auto& p : count) {
        if (p.second != deg)
            continue;
        int x = p.first;
        ans = std::min(ans, last[x] - first[x] + 1);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Degree of an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 2, 3, 1};
    std::cout << "[1,2,2,3,1] -> " << findShortestSubArray(v1) << "\n";

    std::vector<int> v2 = {1, 2, 2, 3, 1, 4, 2};
    std::cout << "[1,2,2,3,1,4,2] -> " << findShortestSubArray(v2) << "\n";
}
