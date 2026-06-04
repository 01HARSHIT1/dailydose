/**
 * Basic DSA - Find X Value of Array I (LeetCode 3524)
 * DP over subarray product remainders; each position adds new ending segments.
 */

#include <iostream>
#include <vector>

std::vector<long long> resultArray(const std::vector<int>& values, int modulus) {
    std::vector<long long> answer(modulus, 0);
    std::vector<long long> endingCounts(modulus, 0);

    for (const int value : values) {
        std::vector<long long> nextCounts(modulus, 0);
        const int valueMod = value % modulus;
        nextCounts[valueMod] = 1;

        for (int remainder = 0; remainder < modulus; ++remainder) {
            const int nextRemainder =
                static_cast<int>((static_cast<long long>(remainder) * valueMod) % modulus);
            nextCounts[nextRemainder] += endingCounts[remainder];
        }

        for (int remainder = 0; remainder < modulus; ++remainder)
            answer[remainder] += nextCounts[remainder];

        endingCounts = std::move(nextCounts);
    }

    return answer;
}

void printCounts(const std::vector<long long>& counts) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(counts.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << counts[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find X Value of Array I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printCounts(resultArray({1, 2, 3, 4, 5}, 3));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printCounts(resultArray({1, 1, 2, 1, 1}, 2));
    std::cout << "\n";
}
