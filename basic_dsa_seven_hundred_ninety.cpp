/**
 * Basic DSA - Concatenated Divisibility (LeetCode 3533)
 * Bitmask DP over used indices and remainder mod k; reconstruct lexicographically.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool canFormDivisibleConcatenation(const std::vector<int>& values,
                                   const std::vector<int>& powers,
                                   std::vector<std::vector<int>>& memo,
                                   int modulus, int mask, int remainder) {
    if (memo[mask][remainder] != -1)
        return memo[mask][remainder] == 1;

    const int count = static_cast<int>(values.size());
    if (mask == (1 << count) - 1) {
        memo[mask][remainder] = remainder == 0 ? 1 : 0;
        return memo[mask][remainder] == 1;
    }

    for (int index = 0; index < count; ++index) {
        if ((mask >> index) & 1)
            continue;

        const int nextRemainder =
            (remainder * powers[index] + values[index] % modulus) % modulus;
        if (canFormDivisibleConcatenation(values, powers, memo, modulus,
                                          mask | (1 << index), nextRemainder)) {
            memo[mask][remainder] = 1;
            return true;
        }
    }

    memo[mask][remainder] = 0;
    return false;
}

std::vector<int> reconstructPermutation(const std::vector<int>& values,
                                        const std::vector<int>& powers,
                                        std::vector<std::vector<int>>& memo,
                                        int modulus, int mask, int remainder) {
    const int count = static_cast<int>(values.size());

    for (int index = 0; index < count; ++index) {
        if ((mask >> index) & 1)
            continue;

        const int nextRemainder =
            (remainder * powers[index] + values[index] % modulus) % modulus;
        if (canFormDivisibleConcatenation(values, powers, memo, modulus,
                                          mask | (1 << index), nextRemainder)) {
            std::vector<int> answer{values[index]};
            const std::vector<int> rest =
                reconstructPermutation(values, powers, memo, modulus,
                                       mask | (1 << index), nextRemainder);
            answer.insert(answer.end(), rest.begin(), rest.end());
            return answer;
        }
    }

    return {};
}

std::vector<int> concatenatedDivisibility(std::vector<int> values, int modulus) {
    std::sort(values.begin(), values.end());

    std::vector<int> powers;
    powers.reserve(values.size());
    for (const int value : values) {
        int digitCount = 0;
        int remaining = value;
        while (remaining > 0) {
            ++digitCount;
            remaining /= 10;
        }

        int power = 1;
        for (int step = 0; step < digitCount; ++step)
            power = (power * 10) % modulus;
        powers.push_back(power);
    }

    const int count = static_cast<int>(values.size());
    std::vector<std::vector<int>> memo(1 << count, std::vector<int>(modulus, -1));

    if (!canFormDivisibleConcatenation(values, powers, memo, modulus, 0, 0))
        return {};

    return reconstructPermutation(values, powers, memo, modulus, 0, 0);
}

void printPermutation(const std::vector<int>& values) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << values[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Concatenated Divisibility\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printPermutation(concatenatedDivisibility({3, 12, 45}, 5));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printPermutation(concatenatedDivisibility({10, 5}, 10));
    std::cout << "\n";

    std::cout << "sample 3 -> ";
    printPermutation(concatenatedDivisibility({1, 2, 3}, 5));
    std::cout << "\n";
}
