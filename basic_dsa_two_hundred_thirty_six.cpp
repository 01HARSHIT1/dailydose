/**
 * Basic DSA - Cells with Odd Values in a Matrix (LeetCode 1252)
 * Count cells with odd values after incrementing rows and columns.
 */
#include <iostream>
#include <vector>

int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
    std::vector<int> row(m, 0), col(n, 0);
    for (auto& p : indices) {
        row[p[0]]++;
        col[p[1]]++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if ((row[i] + col[j]) % 2) ans++;
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Cells with Odd Values in a Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> idx1 = {{0,1},{1,1}};
    std::cout << "m=2, n=3, indices=[[0,1],[1,1]] -> " << oddCells(2, 3, idx1) << "\n";

    std::vector<std::vector<int>> idx2 = {{1,1},{0,0}};
    std::cout << "m=2, n=2, indices=[[1,1],[0,0]] -> " << oddCells(2, 2, idx2) << "\n";
}
