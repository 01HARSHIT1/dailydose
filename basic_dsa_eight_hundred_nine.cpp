/**
 * Basic DSA - Find Sum of Array Product of Magical Sequences (LeetCode 3539)
 * Digit-DP over index counts with popcount carry for set-bit constraint.
 */

#include <iostream>
#include <vector>

static constexpr int kMod = 1'000'000'007;

int popCount(unsigned value) { return __builtin_popcount(value); }

long long modPow(long long base, long long exponent) {
    if (exponent == 0)
        return 1;

    if (exponent % 2 == 1)
        return base * modPow(base % kMod, exponent - 1) % kMod;

    return modPow(base * base % kMod, exponent / 2);
}

std::vector<std::vector<int>> buildCombinations(int maximum) {
    std::vector<std::vector<int>> combinations(maximum + 1,
                                                std::vector<int>(maximum + 1, 0));

    for (int value = 0; value <= maximum; ++value)
        combinations[value][0] = 1;

    for (int value = 1; value <= maximum; ++value) {
        for (int choose = 1; choose <= maximum; ++choose) {
            combinations[value][choose] =
                (combinations[value - 1][choose] + combinations[value - 1][choose - 1]) %
                kMod;
        }
    }

    return combinations;
}

int magicalSum(const std::vector<int>& values,
               std::vector<std::vector<std::vector<std::vector<int>>>>& memo,
               const std::vector<std::vector<int>>& combinations, int remaining,
               int requiredBits, int valueIndex, unsigned carry) {
    if (remaining < 0 || requiredBits < 0 ||
        remaining + static_cast<int>(popCount(carry)) < requiredBits) {
        return 0;
    }

    if (remaining == 0)
        return requiredBits == static_cast<int>(popCount(carry)) ? 1 : 0;

    if (valueIndex == static_cast<int>(values.size()))
        return 0;

    if (memo[remaining][requiredBits][valueIndex][carry] != -1)
        return memo[remaining][requiredBits][valueIndex][carry];

    int result = 0;

    for (int pickCount = 0; pickCount <= remaining; ++pickCount) {
        const long long contribution =
            static_cast<long long>(combinations[remaining][pickCount]) *
            modPow(values[valueIndex], pickCount) % kMod;
        const unsigned nextCarry = carry + static_cast<unsigned>(pickCount);

        result = (result +
                  static_cast<long long>(magicalSum(
                      values, memo, combinations, remaining - pickCount,
                      requiredBits - static_cast<int>(nextCarry % 2), valueIndex + 1,
                      nextCarry / 2)) *
                      contribution) %
                 kMod;
    }

    return memo[remaining][requiredBits][valueIndex][carry] = result;
}

int magicalSequenceProductSum(int sequenceLength, int setBitCount,
                              const std::vector<int>& values) {
    const std::vector<std::vector<int>> combinations =
        buildCombinations(sequenceLength);
    std::vector<std::vector<std::vector<std::vector<int>>>> memo(
        sequenceLength + 1,
        std::vector<std::vector<std::vector<int>>>(
            setBitCount + 1, std::vector<std::vector<int>>(
                                 values.size() + 1,
                                 std::vector<int>(sequenceLength + 1, -1))));

    return magicalSum(values, memo, combinations, sequenceLength, setBitCount, 0,
                      0);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Sum of Array Product of Magical Sequences\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << magicalSequenceProductSum(
                     2, 2, {5, 4, 3, 2, 1})
              << "\n";

    std::cout << "sample 2 -> "
              << magicalSequenceProductSum(1, 1, {28}) << "\n";

    std::cout << "sample 3 -> "
              << magicalSequenceProductSum(
                     5, 5, {1, 10, 100, 10000, 1000000})
              << "\n";
}
