"""
Basic DSA - Valid Sudoku
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated
according to Sudoku rules.
"""


def is_valid_sudoku(board):
    """
    Track seen numbers in rows, cols, and 3x3 boxes.
    Time Complexity: O(81)
    Space Complexity: O(81)
    """
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]

    for r in range(9):
        for c in range(9):
            ch = board[r][c]
            if ch == ".":
                continue
            b = (r // 3) * 3 + (c // 3)
            if ch in rows[r] or ch in cols[c] or ch in boxes[b]:
                return False
            rows[r].add(ch)
            cols[c].add(ch)
            boxes[b].add(ch)
    return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Sudoku")
    print("=" * 60)

    good = [
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
    bad = [
        ["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]

    print(is_valid_sudoku(good))  # True
    print(is_valid_sudoku(bad))  # False
