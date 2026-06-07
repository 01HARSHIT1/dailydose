/**
 * Basic DSA - Grid Teleportation Traversal (LeetCode 3552)
 * 0-1 BFS with zero-cost portal jumps to each letter once.
 */

#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int minimumGridMoves(const std::vector<std::string>& grid) {
    const int rowCount = static_cast<int>(grid.size());
    const int columnCount = static_cast<int>(grid[0].size());

    if (grid.back().back() == '#')
        return -1;

    std::unordered_map<char, std::vector<std::pair<int, int>>> portalCells;
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column) {
            const char cell = grid[row][column];
            if (cell >= 'A' && cell <= 'Z')
                portalCells[cell].emplace_back(row, column);
        }
    }

    const int rowDirections[4] = {-1, 0, 1, 0};
    const int columnDirections[4] = {0, 1, 0, -1};
    const int infinity = INT_MAX / 2;

    std::vector<std::vector<int>> distance(rowCount,
                                           std::vector<int>(columnCount, infinity));
    distance[0][0] = 0;

    std::deque<std::pair<int, int>> queue;
    queue.emplace_back(0, 0);

    while (!queue.empty()) {
        const std::pair<int, int> current = queue.front();
        queue.pop_front();

        const int row = current.first;
        const int column = current.second;
        const int currentDistance = distance[row][column];

        if (row == rowCount - 1 && column == columnCount - 1)
            return currentDistance;

        const char portalLetter = grid[row][column];
        if (portalLetter >= 'A' && portalLetter <= 'Z') {
            const auto portalIterator = portalCells.find(portalLetter);
            if (portalIterator != portalCells.end()) {
                for (const std::pair<int, int>& portalCell : portalIterator->second) {
                    if (currentDistance < distance[portalCell.first][portalCell.second]) {
                        distance[portalCell.first][portalCell.second] = currentDistance;
                        queue.emplace_front(portalCell.first, portalCell.second);
                    }
                }
                portalCells.erase(portalIterator);
            }
        }

        for (int direction = 0; direction < 4; ++direction) {
            const int nextRow = row + rowDirections[direction];
            const int nextColumn = column + columnDirections[direction];

            if (nextRow < 0 || nextRow >= rowCount || nextColumn < 0 ||
                nextColumn >= columnCount) {
                continue;
            }

            if (grid[nextRow][nextColumn] == '#')
                continue;

            if (currentDistance + 1 < distance[nextRow][nextColumn]) {
                distance[nextRow][nextColumn] = currentDistance + 1;
                queue.emplace_back(nextRow, nextColumn);
            }
        }
    }

    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Grid Teleportation Traversal\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << minimumGridMoves({"A..", ".A.", "..."}) << "\n";

    std::cout << "sample 2 -> "
              << minimumGridMoves({".#...", ".#.#.", ".#.#.", "...#."}) << "\n";
}
