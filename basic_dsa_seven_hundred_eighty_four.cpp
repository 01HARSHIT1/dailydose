/**
 * Basic DSA - Count Cells in Overlapping Horizontal and Vertical Substrings
 * (LeetCode 3529)
 * Rolling hash on row-major and column-major flattenings; count dual matches.
 */

#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr long kHashBase = 13;
constexpr long kHashMod = 1'000'000'007;

std::vector<std::vector<bool>> markMatchedCells(const std::string& flattenedGrid,
                                                const std::string& pattern, int rowCount,
                                                int columnCount, bool isHorizontal) {
    std::vector<std::vector<bool>> matchMatrix(rowCount,
                                               std::vector<bool>(columnCount, false));
    std::vector<int> matchPrefix(flattenedGrid.size() + 1, 0);
    std::vector<long> powers{1};
    long patternHash = 0;
    long runningHash = 0;

    for (int index = 1; index < static_cast<int>(pattern.size()); ++index)
        powers.push_back((powers.back() * kHashBase) % kHashMod);

    for (const char character : pattern)
        patternHash = (patternHash * kHashBase + (character - 'a')) % kHashMod;

    const int patternLength = static_cast<int>(pattern.size());
    for (int index = 0; index < static_cast<int>(flattenedGrid.size()); ++index) {
        runningHash =
            (runningHash * kHashBase + (flattenedGrid[index] - 'a')) % kHashMod;

        if (index >= patternLength - 1) {
            if (runningHash == patternHash) {
                ++matchPrefix[index - patternLength + 1];
                --matchPrefix[index + 1];
            }

            const long oldestLetterHash =
                (powers[patternLength - 1] *
                 (flattenedGrid[index - patternLength + 1] - 'a')) %
                kHashMod;
            runningHash = (runningHash - oldestLetterHash + kHashMod) % kHashMod;
        }
    }

    for (int position = 0; position < static_cast<int>(flattenedGrid.size()); ++position) {
        if (position > 0)
            matchPrefix[position] += matchPrefix[position - 1];

        if (matchPrefix[position] > 0) {
            const int row = isHorizontal ? position / columnCount : position % rowCount;
            const int column = isHorizontal ? position % columnCount : position / rowCount;
            matchMatrix[row][column] = true;
        }
    }

    return matchMatrix;
}
}  // namespace

int countCells(const std::vector<std::vector<char>>& grid,
               const std::string& pattern) {
    const int rowCount = static_cast<int>(grid.size());
    const int columnCount = static_cast<int>(grid[0].size());
    std::string rowMajor;
    std::string columnMajor;

    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column)
            rowMajor += grid[row][column];
    }

    for (int column = 0; column < columnCount; ++column) {
        for (int row = 0; row < rowCount; ++row)
            columnMajor += grid[row][column];
    }

    const std::vector<std::vector<bool>> horizontalMatches =
        markMatchedCells(rowMajor, pattern, rowCount, columnCount, true);
    const std::vector<std::vector<bool>> verticalMatches =
        markMatchedCells(columnMajor, pattern, rowCount, columnCount, false);

    int overlapCount = 0;
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column) {
            if (horizontalMatches[row][column] && verticalMatches[row][column])
                ++overlapCount;
        }
    }

    return overlapCount;
}

std::vector<std::vector<char>> makeGrid(
    const std::vector<std::string>& rows) {
    std::vector<std::vector<char>> grid;
    for (const std::string& row : rows) {
        grid.emplace_back(row.begin(), row.end());
    }
    return grid;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Cells in Overlapping Horizontal and Vertical Substrings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << countCells(makeGrid({"caaa", "aaba", "bbaa", "aaba"}), "aba") << "\n";

    std::cout << "sample 2 -> " << countCells(makeGrid({"a"}), "a") << "\n";
}
