"""
Basic DSA - Valid Sudoku
Determine if a 9x9 Sudoku board is valid. Only filled cells need to be validated.
"""


def is_valid_sudoku(board):
    """
    Track seen digits in rows, cols, and 3x3 boxes.
    Time Complexity: O(81)
    Space Complexity: O(81)
    """
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]

    for r in range(9):
        for c in range(9):
            v = board[r][c]
            if v == ".":
                continue
            b = (r // 3) * 3 + (c // 3)
            if v in rows[r] or v in cols[c] or v in boxes[b]:
                return False
            rows[r].add(v)
            cols[c].add(v)
            boxes[b].add(v)
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Sudoku")
    print("=" * 60)

    board_valid = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    print(is_valid_sudoku(board_valid))  # True

    board_invalid = [row[:] for row in board_valid]
    board_invalid[0][1] = "5"  # duplicate 5 in row 0
    print(is_valid_sudoku(board_invalid))  # False

