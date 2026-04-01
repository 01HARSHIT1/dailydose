/**
 * Basic DSA - Longest Subsequence With Limited Sum (LeetCode 2389)
 * For each query, max subsequence length from nums with sum <= query (greedy: smallest first).
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
    std::sort(nums.begin(), nums.end());
    std::vector<long long> pref(nums.size());
    for (size_t i = 0; i < nums.size(); ++i)
        pref[i] = nums[i] + (i ? pref[i - 1] : 0LL);
    std::vector<int> out;
    out.reserve(queries.size());
    for (int q : queries) {
        auto it = std::upper_bound(pref.begin(), pref.end(), static_cast<long long>(q));
        out.push_back(static_cast<int>(it - pref.begin()));
    }
    return out;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Subsequence With Limited Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> nums = {4, 5, 2, 1};
    std::vector<int> queries = {3, 10, 21};
    printVec(nums);
    std::cout << " | queries ";
    printVec(queries);
    std::cout << " -> ";
    printVec(answerQueries(nums, queries));
    std::cout << "\n";
}
