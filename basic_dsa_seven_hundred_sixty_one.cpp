/**
 * Basic DSA - Minimum Operations to Make Array Elements Zero (LeetCode 3495)
 * Prefix-sum helper over operation counts, then halve per query range.
 */

#include <algorithm>
#include <iostream>
#include <vector>

long long operationPrefixSum(int limit) {
    if (limit <= 0)
        return 0;

    long long total = 0;
    int depth = 0;

    for (long long power = 1; power <= limit; power *= 4) {
        const long long left = power;
        const long long right = std::min<long long>(limit, power * 4 - 1);
        ++depth;
        total += (right - left + 1) * depth;
    }

    return total;
}

long long minOperations(const std::vector<std::vector<int>>& queries) {
    long long answer = 0;

    for (const auto& query : queries) {
        const int left = query[0];
        const int right = query[1];
        answer += (operationPrefixSum(right) - operationPrefixSum(left - 1) + 1) / 2;
    }

    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Make Array Elements Zero\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minOperations({{1, 2}, {2, 4}}) << "\n";
    std::cout << "sample 2 -> " << minOperations({{2, 6}}) << "\n";
}
