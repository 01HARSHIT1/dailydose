/**
 * Basic DSA - Zero Array Transformation IV (LeetCode 3489)
 * Per index, find earliest query prefix that can subtract to zero via bitset DP.
 */

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

int minZeroArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries) {
    const int elementCount = static_cast<int>(nums.size());
    const int queryCount = static_cast<int>(queries.size());
    int answer = 0;

    for (int index = 0; index < elementCount; ++index) {
        if (nums[index] == 0)
            continue;

        std::bitset<1001> reachable;
        reachable[nums[index]] = 1;
        int roundsNeeded = -1;

        for (int queryIndex = 0; queryIndex < queryCount; ++queryIndex) {
            const int left = queries[queryIndex][0];
            const int right = queries[queryIndex][1];
            const int value = queries[queryIndex][2];

            if (left <= index && index <= right)
                reachable |= (reachable >> value);

            if (reachable[0]) {
                roundsNeeded = queryIndex + 1;
                break;
            }
        }

        if (roundsNeeded == -1)
            return -1;

        answer = std::max(answer, roundsNeeded);
    }

    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Zero Array Transformation IV\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << minZeroArray({2, 0, 2}, {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}}) << "\n";
    std::cout << "sample 2 -> "
              << minZeroArray({4, 3, 2, 1}, {{1, 3, 2}, {0, 2, 1}}) << "\n";
}
