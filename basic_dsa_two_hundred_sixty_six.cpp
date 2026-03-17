/**
 * Basic DSA - Last Stone Weight (LeetCode 1046)
 * Smash heaviest two stones; return last stone weight or 0.
 */
#include <iostream>
#include <vector>
#include <queue>

int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if (a != b) pq.push(a - b);
    }
    return pq.empty() ? 0 : pq.top();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Last Stone Weight\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 7, 4, 1, 8, 1};
    std::cout << "[2,7,4,1,8,1] -> " << lastStoneWeight(v1) << "\n";

    std::vector<int> v2 = {1};
    std::cout << "[1] -> " << lastStoneWeight(v2) << "\n";
}
