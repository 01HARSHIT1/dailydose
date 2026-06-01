/**
 * Basic DSA - Maximize Profit from Task Assignment (LeetCode 3476)
 * Assign workers to matching-skill tasks; one extra worker can take any leftover task.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

long long maxProfit(const std::vector<int>& workers, const std::vector<std::vector<int>>& tasks) {
    std::unordered_map<int, std::vector<int>> skillToProfits;

    for (const auto& task : tasks)
        skillToProfits[task[0]].push_back(task[1]);

    for (auto& entry : skillToProfits)
        std::sort(entry.second.rbegin(), entry.second.rend());

    long long total = 0;
    for (int skill : workers) {
        auto it = skillToProfits.find(skill);
        if (it == skillToProfits.end() || it->second.empty())
            continue;
        total += it->second.front();
        it->second.erase(it->second.begin());
    }

    int bestRemaining = 0;
    for (const auto& entry : skillToProfits) {
        if (!entry.second.empty())
            bestRemaining = std::max(bestRemaining, entry.second.front());
    }

    return total + bestRemaining;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Profit from Task Assignment\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxProfit({1, 2, 3, 4, 5}, {{1, 100}, {2, 400}, {3, 100}, {3, 400}}) << "\n";
    std::cout << "sample 2 -> " << maxProfit({10, 10000, 100000000}, {{1, 100}}) << "\n";
    std::cout << "sample 3 -> " << maxProfit({7}, {{3, 3}, {3, 3}}) << "\n";
}
