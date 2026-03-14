/**
 * Basic DSA - Search a 2D Matrix (LeetCode 74)
 * Search target in matrix where each row is sorted and first of row > last of previous.
 */
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m * n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int r = mid / n, c = mid % n;
        if (matrix[r][c] == target) return true;
        if (matrix[r][c] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Search a 2D Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    std::cout << "target=3 -> " << (searchMatrix(m1, 3) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> m2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    std::cout << "target=13 -> " << (searchMatrix(m2, 13) ? "true" : "false") << "\n";
}
