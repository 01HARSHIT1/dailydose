/**
 * Basic DSA - Car Pooling (LeetCode 1094)
 * trips[i] = [passengers, start, end). Difference array on stops up to 1000; prefix load must never exceed capacity.
 */
#include <iostream>
#include <vector>

bool carPooling(const std::vector<std::vector<int>>& trips, int capacity) {
    int diff[1001] = {0};
    for (const auto& t : trips) {
        diff[t[1]] += t[0];
        diff[t[2]] -= t[0];
    }
    int cur = 0;
    for (int i = 0; i <= 1000; ++i) {
        cur += diff[i];
        if (cur > capacity)
            return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Car Pooling\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> t1 = {{2, 1, 5}, {3, 3, 7}};
    std::cout << "cap=4 -> " << (carPooling(t1, 4) ? "true" : "false") << "\n";
    std::cout << "cap=5 -> " << (carPooling(t1, 5) ? "true" : "false") << "\n";
}
