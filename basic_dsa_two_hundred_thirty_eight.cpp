/**
 * Basic DSA - Available Captures for Rook (LeetCode 999)
 * Count pawns a rook can capture (rook moves until blocked).
 */
#include <iostream>
#include <vector>

int numRookCaptures(std::vector<std::vector<char>>& board) {
    int ri = -1, rj = -1;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j] == 'R') { ri = i; rj = j; break; }
    if (ri < 0) return 0;
    int ans = 0;
    for (int j = rj - 1; j >= 0; j--) {
        if (board[ri][j] == 'p') { ans++; break; }
        if (board[ri][j] == 'B') break;
    }
    for (int j = rj + 1; j < 8; j++) {
        if (board[ri][j] == 'p') { ans++; break; }
        if (board[ri][j] == 'B') break;
    }
    for (int i = ri - 1; i >= 0; i--) {
        if (board[i][rj] == 'p') { ans++; break; }
        if (board[i][rj] == 'B') break;
    }
    for (int i = ri + 1; i < 8; i++) {
        if (board[i][rj] == 'p') { ans++; break; }
        if (board[i][rj] == 'B') break;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Available Captures for Rook\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<char>> b1 = {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    std::cout << "Board with R at (2,3) -> " << numRookCaptures(b1) << "\n";

    std::vector<std::vector<char>> b2 = {
        {'.','.','.','.','.','.','.','.'},
        {'.','p','p','p','p','p','.','.'},
        {'.','p','p','B','p','p','.','.'},
        {'.','p','B','R','B','p','.','.'},
        {'.','p','p','B','p','p','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    std::cout << "Board with bishops blocking -> " << numRookCaptures(b2) << "\n";
}
