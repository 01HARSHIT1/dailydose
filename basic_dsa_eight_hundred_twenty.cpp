/**
 * Basic DSA - Maximum Profit from Trading Stocks with Discounts (LeetCode 3562)
 * Tree DP with knapsack merge; half price when direct boss buys stock.
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

class StockDiscountProfitSolver {
public:
    StockDiscountProfitSolver(const std::vector<int>& presentPrices,
                              const std::vector<int>& futurePrices,
                              const std::vector<std::vector<int>>& hierarchy,
                              int investmentBudget)
        : presentPrices_(presentPrices),
          futurePrices_(futurePrices),
          investmentBudget_(investmentBudget) {
        const int employeeCount = static_cast<int>(presentPrices.size());
        childrenByEmployee_.assign(employeeCount + 1, {});

        for (const std::vector<int>& edge : hierarchy) {
            const int manager = edge[0];
            const int employee = edge[1];
            childrenByEmployee_[manager].push_back(employee);
        }
    }

    int maximumProfit() const {
        const std::vector<std::array<int, 2>> profitTable =
            computeSubtreeProfit(1);
        return profitTable[investmentBudget_][0];
    }

private:
    std::vector<int> presentPrices_;
    std::vector<int> futurePrices_;
    int investmentBudget_;
    std::vector<std::vector<int>> childrenByEmployee_;

    std::vector<std::array<int, 2>> computeSubtreeProfit(int employee) const {
        std::vector<std::array<int, 2>> mergedChildProfit(
            investmentBudget_ + 1, {0, 0});

        for (const int childEmployee : childrenByEmployee_[employee]) {
            const std::vector<std::array<int, 2>> childProfit =
                computeSubtreeProfit(childEmployee);

            for (int totalBudget = investmentBudget_; totalBudget >= 0;
                 --totalBudget) {
                for (int childBudget = 0; childBudget <= totalBudget;
                     ++childBudget) {
                    for (int bossBought = 0; bossBought < 2; ++bossBought) {
                        const int candidate =
                            mergedChildProfit[totalBudget - childBudget]
                                               [bossBought] +
                            childProfit[childBudget][bossBought];
                        mergedChildProfit[totalBudget][bossBought] =
                            std::max(mergedChildProfit[totalBudget][bossBought],
                                     candidate);
                    }
                }
            }
        }

        std::vector<std::array<int, 2>> employeeProfit(investmentBudget_ + 1,
                                                       {0, 0});
        const int sellPrice = futurePrices_[employee - 1];

        for (int totalBudget = 0; totalBudget <= investmentBudget_;
             ++totalBudget) {
            for (int bossBought = 0; bossBought < 2; ++bossBought) {
                const int buyCost =
                    presentPrices_[employee - 1] / (bossBought + 1);
                if (totalBudget >= buyCost) {
                    employeeProfit[totalBudget][bossBought] = std::max(
                        mergedChildProfit[totalBudget][0],
                        mergedChildProfit[totalBudget - buyCost][1] +
                            (sellPrice - buyCost));
                } else {
                    employeeProfit[totalBudget][bossBought] =
                        mergedChildProfit[totalBudget][0];
                }
            }
        }

        return employeeProfit;
    }
};

int maximumStockDiscountProfit(int employeeCount,
                               const std::vector<int>& presentPrices,
                               const std::vector<int>& futurePrices,
                               const std::vector<std::vector<int>>& hierarchy,
                               int investmentBudget) {
    StockDiscountProfitSolver solver(
        presentPrices, futurePrices, hierarchy, investmentBudget);
    (void)employeeCount;
    return solver.maximumProfit();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Profit from Trading Stocks with Discounts\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maximumStockDiscountProfit(
                     2, {1, 2}, {4, 3}, {{1, 2}}, 3)
              << "\n";
    std::cout << "sample 2 -> "
              << maximumStockDiscountProfit(
                     2, {3, 4}, {5, 8}, {{1, 2}}, 4)
              << "\n";
    std::cout << "sample 3 -> "
              << maximumStockDiscountProfit(
                     3, {4, 6, 8}, {7, 9, 11}, {{1, 2}, {1, 3}}, 10)
              << "\n";
    std::cout << "sample 4 -> "
              << maximumStockDiscountProfit(
                     3, {5, 2, 3}, {8, 5, 6}, {{1, 2}, {2, 3}}, 7)
              << "\n";
}
