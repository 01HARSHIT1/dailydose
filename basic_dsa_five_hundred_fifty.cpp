/**
 * Basic DSA - Flood Fill (LeetCode 733)
 * Starting pixel (sr, sc), paint 4-connected cells that match the start color with `color`. BFS queue.
 */
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> image, int sr, int sc, int color) {
    int orig = image[static_cast<size_t>(sr)][static_cast<size_t>(sc)];
    if (orig == color)
        return image;
    int m = static_cast<int>(image.size());
    int n = static_cast<int>(image[0].size());
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        std::pair<int, int> cell = q.front();
        q.pop();
        int r = cell.first;
        int c = cell.second;
        if (r < 0 || r >= m || c < 0 || c >= n)
            continue;
        if (image[static_cast<size_t>(r)][static_cast<size_t>(c)] != orig)
            continue;
        image[static_cast<size_t>(r)][static_cast<size_t>(c)] = color;
        for (int d = 0; d < 4; ++d)
            q.push({r + dr[d], c + dc[d]});
    }
    return image;
}

void printGrid(const std::vector<std::vector<int>>& g) {
    for (const auto& row : g) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (j) std::cout << ' ';
            std::cout << row[j];
        }
        std::cout << "\n";
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Flood Fill\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> img = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    auto out = floodFill(img, 1, 1, 2);
    printGrid(out);
}
