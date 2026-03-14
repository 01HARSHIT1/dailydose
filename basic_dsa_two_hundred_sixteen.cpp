/**
 * Basic DSA - Kth Smallest Element in a Sorted Matrix (LeetCode 378)
 * Find kth smallest element in n x n matrix where each row/col is sorted.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    int n = matrix.size();
    std::vector<int> flat;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            flat.push_back(matrix[i][j]);
    std::nth_element(flat.begin(), flat.begin() + k - 1, flat.end());
    return flat[k - 1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Kth Smallest Element in a Sorted Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    std::cout << "[[1,5,9],[10,11,13],[12,13,15]], k=8 -> " << kthSmallest(m1, 8) << "\n";

    std::vector<std::vector<int>> m2 = {{-5}};
    std::cout << "[[-5]], k=1 -> " << kthSmallest(m2, 1) << "\n";
}
