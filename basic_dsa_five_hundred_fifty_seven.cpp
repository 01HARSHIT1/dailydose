/**
 * Basic DSA - Swim in Rising Water (LeetCode 778)
 * Minimax path from top-left to bottom-right: cost to a cell is max elevation along best route. Dijkstra on max-so-far.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int swimInWater(const std::vector<std::vector<int>>& grid) {
    int n = static_cast<int>(grid.size());
    std::vector<std::vector<int>> dist(static_cast<size_t>(n), std::vector<int>(static_cast<size_t>(n), INT_MAX));
    dist[0][0] = grid[0][0];

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
    pq.push({dist[0][0], 0, 0});
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        std::tuple<int, int, int> top = pq.top();
        pq.pop();
        int d = std::get<0>(top);
        int r = std::get<1>(top);
        int c = std::get<2>(top);
        if (d != dist[static_cast<size_t>(r)][static_cast<size_t>(c)])
            continue;
        if (r == n - 1 && c == n - 1)
            return d;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;
            int nd = std::max(d, grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)]);
            if (nd < dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)]) {
                dist[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = nd;
                pq.push({nd, nr, nc});
            }
        }
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Swim in Rising Water\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "2x2 small           -> " << swimInWater({{0, 2}, {1, 3}}) << "\n";
    std::vector<std::vector<int>> big = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}};
    std::cout << "5x5 spiral sample   -> " << swimInWater(big) << "\n";
}
