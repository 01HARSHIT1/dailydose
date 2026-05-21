/**
 * Basic DSA - Maximal Score After Applying K Operations (LeetCode 2530)
 * Repeatedly take the current maximum, add it to the score, and push ceil(max/3) back into the heap.
 */
#include <iostream>
#include <queue>
#include <vector>

long long maxKelements(const std::vector<int>& nums, int k) {
    std::priority_queue<int> heap(nums.begin(), nums.end());
    long long score = 0;
    while (k-- > 0) {
        int top = heap.top();
        heap.pop();
        score += top;
        heap.push((top + 2) / 3);
    }
    return score;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximal Score After Applying K Operations\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxKelements({10, 10, 10, 10, 10}, 5) << "\n";
    std::cout << "sample 2 -> " << maxKelements({1, 10, 3, 3, 3}, 3) << "\n";
}
