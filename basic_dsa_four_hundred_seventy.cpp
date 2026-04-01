/**
 * Basic DSA - Count Elements With Maximum Frequency (LeetCode 3005)
 * Sum of occurrences among values that share the maximum frequency.
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int maxFrequencyElements(const std::vector<int>& nums) {
    std::unordered_map<int, int> cnt;
    int mx = 0;
    for (int x : nums)
        mx = std::max(mx, ++cnt[x]);
    int ans = 0;
    for (const auto& p : cnt) {
        if (p.second == mx)
            ans += p.second;
    }
    return ans;
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
    std::cout << "Problem: Count Elements With Maximum Frequency\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 2, 3, 1, 4};
    printVec(a1);
    std::cout << " -> " << maxFrequencyElements(a1) << "\n";

    std::vector<int> a2 = {1, 2, 3, 4, 5};
    printVec(a2);
    std::cout << " -> " << maxFrequencyElements(a2) << "\n";

    std::vector<int> a3 = {11, 33, 22};
    printVec(a3);
    std::cout << " -> " << maxFrequencyElements(a3) << "\n";
}
