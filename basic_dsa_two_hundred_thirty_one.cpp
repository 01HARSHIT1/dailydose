/**
 * Basic DSA - Image Overlap (LeetCode 835)
 * Largest overlap of two binary images (shift one over the other).
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
    int n = img1.size();
    std::vector<std::pair<int,int>> a, b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (img1[i][j]) a.push_back({i, j});
            if (img2[i][j]) b.push_back({i, j});
        }
    std::map<std::string, int> cnt;
    for (auto& p : a)
        for (auto& q : b)
            cnt[std::to_string(p.first - q.first) + "," + std::to_string(p.second - q.second)]++;
    int ans = 0;
    for (auto& p : cnt) ans = std::max(ans, p.second);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Image Overlap\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{1,1,0},{0,1,0},{0,1,0}};
    std::vector<std::vector<int>> b1 = {{0,0,0},{0,1,1},{0,0,1}};
    std::cout << "Overlap -> " << largestOverlap(a1, b1) << "\n";

    std::vector<std::vector<int>> a2 = {{1}};
    std::vector<std::vector<int>> b2 = {{1}};
    std::cout << "[[1]] + [[1]] -> " << largestOverlap(a2, b2) << "\n";
}
