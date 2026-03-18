/**
 * Basic DSA - Top K Frequent Elements (LeetCode 347)
 * Return k most frequent elements.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> cnt;
    for (int x : nums) cnt[x]++;
    std::vector<std::pair<int, int>> v(cnt.begin(), cnt.end());
    std::partial_sort(v.begin(), v.begin() + k, v.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });
    std::vector<int> ans;
    for (int i = 0; i < k; i++) ans.push_back(v[i].first);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Top K Frequent Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 1, 2, 2, 3};
    auto r1 = topKFrequent(v1, 2);
    std::cout << "[1,1,1,2,2,3], 2 -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {1};
    auto r2 = topKFrequent(v2, 1);
    std::cout << "[1], 1 -> [" << r2[0] << "]\n";
}
