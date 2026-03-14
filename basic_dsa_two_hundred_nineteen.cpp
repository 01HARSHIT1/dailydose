/**
 * Basic DSA - Search a 2D Matrix II (LeetCode 240)
 * Search target in matrix sorted row-wise and column-wise (not strictly).
 */
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int r = 0, c = (int)matrix[0].size() - 1;
    while (r < (int)matrix.size() && c >= 0) {
        if (matrix[r][c] == target) return true;
        if (matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Search a 2D Matrix II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    std::cout << "target=5 -> " << (searchMatrix(m1, 5) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> m2 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    std::cout << "target=20 -> " << (searchMatrix(m2, 20) ? "true" : "false") << "\n";
}
