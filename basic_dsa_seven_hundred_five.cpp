/**
 * Basic DSA - Zigzag Grid Traversal With Skip (LeetCode 3417)
 * Traverse rows in alternating directions and collect every other cell globally.
 */
#include <iostream>
#include <vector>

std::vector<int> zigzagTraversal(const std::vector<std::vector<int>>& grid) {
    std::vector<int> result;
    bool take = true;

    for (int row = 0; row < static_cast<int>(grid.size()); ++row) {
        if (row % 2 == 0) {
            for (int value : grid[static_cast<size_t>(row)]) {
                if (take)
                    result.push_back(value);
                take = !take;
            }
        } else {
            for (int col = static_cast<int>(grid[static_cast<size_t>(row)].size()) - 1; col >= 0; --col) {
                if (take)
                    result.push_back(grid[static_cast<size_t>(row)][static_cast<size_t>(col)]);
                take = !take;
            }
        }
    }
    return result;
}

void printArray(const std::vector<int>& nums) {
    std::cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << nums[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Zigzag Grid Traversal With Skip\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printArray(zigzagTraversal({{1, 2}, {3, 4}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printArray(zigzagTraversal({{2, 1}, {2, 1}, {2, 1}}));
    std::cout << "\n";

    std::cout << "sample 3 -> ";
    printArray(zigzagTraversal({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
    std::cout << "\n";
}
