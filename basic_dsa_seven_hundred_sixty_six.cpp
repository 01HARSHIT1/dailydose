/**
 * Basic DSA - Find Time Required to Eliminate Bacterial Strains (LeetCode 3506)
 * Greedy min-heap merge: combine two smallest strains with split overhead.
 */

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

long long minEliminationTime(const std::vector<int>& timeReq, int splitTime) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> heap;

    for (const int time : timeReq)
        heap.push(time);

    while (heap.size() > 1) {
        const long long first = heap.top();
        heap.pop();
        const long long second = heap.top();
        heap.pop();
        heap.push(static_cast<long long>(splitTime) + std::max(first, second));
    }

    return heap.top();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Time Required to Eliminate Bacterial Strains\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minEliminationTime({10, 4, 5}, 2) << "\n";
    std::cout << "sample 2 -> " << minEliminationTime({10, 4}, 5) << "\n";
}
