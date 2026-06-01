/**
 * Basic DSA - Maximize the Distance Between Points on a Square (LeetCode 3464)
 * Binary search the answer on a flattened square perimeter with greedy selection.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int maxDistance(int side, std::vector<std::vector<int>> points, int k) {
    std::vector<int> positions;
    positions.reserve(points.size());

    for (const auto& point : points) {
        const int x = point[0];
        const int y = point[1];

        if (x == 0)
            positions.push_back(y);
        else if (y == side)
            positions.push_back(side + x);
        else if (x == side)
            positions.push_back(3 * side - y);
        else
            positions.push_back(4 * side - x);
    }

    std::sort(positions.begin(), positions.end());

    const auto canSelect = [&](int limit) {
        const int perimeter = 4 * side;

        for (int start : positions) {
            const int end = start + perimeter - limit;
            int current = start;
            bool valid = true;

            for (int count = 1; count < k; ++count) {
                const auto iterator =
                    std::lower_bound(positions.begin(), positions.end(), current + limit);
                if (iterator == positions.end() || *iterator > end) {
                    valid = false;
                    break;
                }
                current = *iterator;
            }

            if (valid)
                return true;
        }

        return false;
    };

    int low = 1;
    int high = side;
    int answer = 0;

    while (low <= high) {
        const int mid = (low + high) / 2;
        if (canSelect(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize the Distance Between Points on a Square\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxDistance(2, {{0, 2}, {2, 0}, {2, 2}, {0, 0}}, 4) << "\n";
    std::cout << "sample 2 -> " << maxDistance(2, {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}}, 4)
              << "\n";
    std::cout << "sample 3 -> "
              << maxDistance(2, {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}}, 5)
              << "\n";
}
