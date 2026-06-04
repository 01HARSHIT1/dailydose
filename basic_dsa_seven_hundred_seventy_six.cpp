/**
 * Basic DSA - Maximum Product of Subsequences With an Alternating Sum Equal to K
 * (LeetCode 3509)
 * Memoized DP over index, remaining alternating sum, product, and parity state.
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

enum class State {
    kFirst,
    kSubtract,
    kAdd
};

class AlternatingProductSolver {
 public:
    int maxProduct(const std::vector<int>& values, int targetSum, int limit) {
        long long totalSum = 0;
        for (const int value : values)
            totalSum += value;

        if (std::abs(targetSum) > totalSum)
            return -1;

        memo_.clear();
        const int answer =
            solve(values, 0, 1, State::kFirst, targetSum, limit);
        return answer == kMinValue ? -1 : answer;
    }

 private:
    static constexpr int kMinValue = -5000;

    std::unordered_map<std::string, int> memo_;

    int solve(const std::vector<int>& values, int index, int product, State state,
              int remainingSum, int limit) {
        if (index == static_cast<int>(values.size())) {
            if (remainingSum == 0 && state != State::kFirst && product <= limit)
                return product;
            return kMinValue;
        }

        const std::string key = std::to_string(index) + "," +
                                std::to_string(remainingSum) + "," +
                                std::to_string(product) + "," +
                                std::to_string(static_cast<int>(state));

        const auto found = memo_.find(key);
        if (found != memo_.end())
            return found->second;

        int best = solve(values, index + 1, product, state, remainingSum, limit);
        const int value = values[index];

        if (state == State::kFirst) {
            best = std::max(
                best, solve(values, index + 1, value, State::kSubtract,
                            remainingSum - value, limit));
        }
        if (state == State::kSubtract) {
            const int nextProduct = std::min(product * value, limit + 1);
            best = std::max(
                best, solve(values, index + 1, nextProduct, State::kAdd,
                            remainingSum + value, limit));
        }
        if (state == State::kAdd) {
            const int nextProduct = std::min(product * value, limit + 1);
            best = std::max(
                best, solve(values, index + 1, nextProduct, State::kSubtract,
                            remainingSum - value, limit));
        }

        memo_[key] = best;
        return best;
    }
};

int maxProduct(const std::vector<int>& values, int targetSum, int limit) {
    AlternatingProductSolver solver;
    return solver.maxProduct(values, targetSum, limit);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Product of Subsequences With an Alternating Sum Equal to K\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxProduct({1, 2, 3}, 2, 10) << "\n";
    std::cout << "sample 2 -> " << maxProduct({0, 2, 3}, -5, 12) << "\n";
    std::cout << "sample 3 -> " << maxProduct({2, 2, 3, 3}, 0, 9) << "\n";
}
