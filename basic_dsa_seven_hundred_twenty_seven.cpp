/**
 * Basic DSA - Eat Pizzas! (LeetCode 3457)
 * Maximize weight gained eating 4 pizzas/day (max on odd days, 2nd max on even days).
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

long long maxWeight(std::vector<int> pizzas) {
    const int n = static_cast<int>(pizzas.size());
    const int days = n / 4;
    const int odd = (days + 1) / 2;
    int even = days - odd;

    std::sort(pizzas.begin(), pizzas.end());

    long long ans = std::accumulate(pizzas.begin() + n - odd, pizzas.end(), 0LL);
    for (int i = n - odd - 2; even > 0; --even) {
        ans += pizzas[i];
        i -= 2;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Eat Pizzas!\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxWeight({1, 2, 3, 4, 5, 6, 7, 8}) << "\n";
    std::cout << "sample 2 -> " << maxWeight({2, 1, 1, 1, 1, 1, 1, 1}) << "\n";
}
