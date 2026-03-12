/**
 * Basic DSA - Valid Sudoku (LeetCode 36)
 * Check if 9x9 Sudoku board is valid (no duplicates in row/col/box).
 */
#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<std::string> seen;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            std::string r = "r" + std::to_string(i) + c;
            std::string col = "c" + std::to_string(j) + c;
            std::string box = "b" + std::to_string(i/3*3 + j/3) + c;
            if (seen.count(r) || seen.count(col) || seen.count(box)) return false;
            seen.insert(r); seen.insert(col); seen.insert(box);
        }
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Sudoku\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<char>> b1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    std::cout << "Valid board -> " << (isValidSudoku(b1) ? "true" : "false") << "\n";

    std::vector<std::vector<char>> b2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    std::cout << "Invalid (duplicate 8 in col 0) -> " << (isValidSudoku(b2) ? "true" : "false") << "\n";
}
