/**
 * Basic DSA - Permutations III (LeetCode 3437)
 * Generate lexicographically sorted alternating permutations of 1..n.
 */

#include <functional>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> alternatingPermutations(int n) {
    std::vector<std::vector<int>> ans;
    std::vector<int> path;
    std::vector<bool> used(n + 1);

    std::function<void(int)> dfs = [&](int index) {
        if (index >= n) {
            ans.push_back(path);
            return;
        }
        for (int value = 1; value <= n; ++value) {
            if (used[value])
                continue;
            if (index > 0 && path.back() % 2 == value % 2)
                continue;

            used[value] = true;
            path.push_back(value);
            dfs(index + 1);
            path.pop_back();
            used[value] = false;
        }
    };

    dfs(0);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Permutations III\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << alternatingPermutations(2).size() << "\n";
    std::cout << "sample 2 -> " << alternatingPermutations(3).size() << "\n";
    std::cout << "sample 3 -> " << alternatingPermutations(4).size() << "\n";
}
