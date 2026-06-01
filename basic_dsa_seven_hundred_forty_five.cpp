/**
 * Basic DSA - Fruits Into Baskets II (LeetCode 3477)
 * Place each fruit in the leftmost unused basket with enough capacity.
 */

#include <iostream>
#include <vector>

int numOfUnplacedFruits(const std::vector<int>& fruits, const std::vector<int>& baskets) {
    const int n = static_cast<int>(fruits.size());
    std::vector<bool> used(n, false);
    int unplaced = n;

    for (int fruit : fruits) {
        for (int i = 0; i < n; ++i) {
            if (!used[i] && baskets[i] >= fruit) {
                used[i] = true;
                --unplaced;
                break;
            }
        }
    }

    return unplaced;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fruits Into Baskets II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << numOfUnplacedFruits({4, 2, 5}, {3, 5, 4}) << "\n";
    std::cout << "sample 2 -> " << numOfUnplacedFruits({3, 6, 1}, {6, 4, 7}) << "\n";
}
