/**
 * Basic DSA - Top K Frequent Elements (LeetCode 347)
 * Return k most frequent elements (bucket sort).
 */
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (auto& p : freq) buckets[p.second].push_back(p.first);
    std::vector<int> out;
    for (int i = (int)buckets.size() - 1; i >= 0 && (int)out.size() < k; i--)
        for (int x : buckets[i]) {
            out.push_back(x);
            if ((int)out.size() == k) break;
        }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Top K Frequent Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 1, 1, 2, 2, 3};
    auto r1 = topKFrequent(a1, 2);
    std::cout << "[1,1,1,2,2,3], k=2 -> [";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {1};
    auto r2 = topKFrequent(a2, 1);
    std::cout << "[1], k=1 -> [1]\n";
}
