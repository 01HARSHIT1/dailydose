/**
 * Basic DSA - Sum of Distances (LeetCode 2615)
 * For each value, sum of |i - j| over equal indices; sweep occurrences left-to-right with running prefix sums.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<long long> distance(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<long long> answer(static_cast<size_t>(n), 0);

    std::unordered_map<int, long long> count;  // occurrences seen so far
    std::unordered_map<int, long long> prefix; // sum of indices seen so far

    for (int i = 0; i < n; ++i) {
        int v = nums[static_cast<size_t>(i)];
        answer[static_cast<size_t>(i)] += static_cast<long long>(i) * count[v] - prefix[v];
        ++count[v];
        prefix[v] += i;
    }

    count.clear();
    prefix.clear();
    for (int i = n - 1; i >= 0; --i) {
        int v = nums[static_cast<size_t>(i)];
        answer[static_cast<size_t>(i)] += prefix[v] - static_cast<long long>(i) * count[v];
        ++count[v];
        prefix[v] += i;
    }
    return answer;
}

void printVec(const std::vector<long long>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Distances\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(distance({1, 3, 1, 1, 2}));
    printVec(distance({0, 5, 3}));
}
