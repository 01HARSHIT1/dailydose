"""
Matrix DSA Interview Problems
Collection of common matrix problems with solutions
"""


# Problem 1: Spiral Matrix
# Traverse matrix in spiral order
def spiral_order(matrix):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(1) excluding output
    """
    if not matrix or not matrix[0]:
        return []
    
    result = []
    top, bottom = 0, len(matrix) - 1
    left, right = 0, len(matrix[0]) - 1
    
    while top <= bottom and left <= right:
        # Traverse right
        for i in range(left, right + 1):
            result.append(matrix[top][i])
        top += 1
        
        # Traverse down
        for i in range(top, bottom + 1):
            result.append(matrix[i][right])
        right -= 1
        
        # Traverse left
        if top <= bottom:
            for i in range(right, left - 1, -1):
                result.append(matrix[bottom][i])
            bottom -= 1
        
        # Traverse up
        if left <= right:
            for i in range(bottom, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
    
    return result


# Problem 2: Spiral Matrix II
# Generate spiral matrix filled with numbers 1 to n^2
def generate_spiral_matrix(n):
    """
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    """
    matrix = [[0] * n for _ in range(n)]
    num = 1
    top, bottom = 0, n - 1
    left, right = 0, n - 1
    
    while top <= bottom and left <= right:
        # Fill right
        for i in range(left, right + 1):
            matrix[top][i] = num
            num += 1
        top += 1
        
        # Fill down
        for i in range(top, bottom + 1):
            matrix[i][right] = num
            num += 1
        right -= 1
        
        # Fill left
        if top <= bottom:
            for i in range(right, left - 1, -1):
                matrix[bottom][i] = num
                num += 1
            bottom -= 1
        
        # Fill up
        if left <= right:
            for i in range(bottom, top - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1
    
    return matrix


# Problem 3: Rotate Image (90 degrees clockwise)
# Rotate matrix in-place by 90 degrees
def rotate_matrix(matrix):
    """
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    n = len(matrix)
    
    # Transpose matrix
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    
    # Reverse each row
    for i in range(n):
        matrix[i].reverse()


# Problem 4: Set Matrix Zeros
# Set entire row and column to zero if element is zero
def set_zeroes(matrix):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(1)
    """
    m, n = len(matrix), len(matrix[0])
    first_row_zero = any(matrix[0][j] == 0 for j in range(n))
    first_col_zero = any(matrix[i][0] == 0 for i in range(m))
    
    # Mark zeros in first row and column
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    
    # Set zeros based on marks
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][0] == 0 or matrix[0][j] == 0:
                matrix[i][j] = 0
    
    # Set first row
    if first_row_zero:
        for j in range(n):
            matrix[0][j] = 0
    
    # Set first column
    if first_col_zero:
        for i in range(m):
            matrix[i][0] = 0


# Problem 5: Search a 2D Matrix
# Search target in sorted matrix (each row and column is sorted)
def search_matrix_2d(matrix, target):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    if not matrix or not matrix[0]:
        return False
    
    m, n = len(matrix), len(matrix[0])
    row, col = 0, n - 1
    
    while row < m and col >= 0:
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1
    
    return False


# Problem 6: Search a 2D Matrix II
# Search in matrix where each row is sorted and each column is sorted
def search_matrix_2d_ii(matrix, target):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    if not matrix or not matrix[0]:
        return False
    
    m, n = len(matrix), len(matrix[0])
    row, col = 0, n - 1
    
    while row < m and col >= 0:
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1
    
    return False


# Problem 7: Number of Islands
# Count number of islands (connected 1s) in matrix
def num_islands(grid):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(m * n) for recursion stack
    """
    if not grid or not grid[0]:
        return 0
    
    m, n = len(grid), len(grid[0])
    count = 0
    
    def dfs(i, j):
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0':
            return
        
        grid[i][j] = '0'  # Mark as visited
        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i, j + 1)
        dfs(i, j - 1)
    
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '1':
                count += 1
                dfs(i, j)
    
    return count


# Problem 8: Max Area of Island
# Find maximum area of island in binary matrix
def max_area_of_island(grid):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
    """
    if not grid or not grid[0]:
        return 0
    
    m, n = len(grid), len(grid[0])
    max_area = 0
    
    def dfs(i, j):
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
            return 0
        
        grid[i][j] = 0  # Mark as visited
        area = 1
        area += dfs(i + 1, j)
        area += dfs(i - 1, j)
        area += dfs(i, j + 1)
        area += dfs(i, j - 1)
        return area
    
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                max_area = max(max_area, dfs(i, j))
    
    return max_area


# Problem 9: Transpose Matrix
# Transpose a matrix
def transpose(matrix):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
    """
    m, n = len(matrix), len(matrix[0])
    result = [[0] * m for _ in range(n)]
    
    for i in range(m):
        for j in range(n):
            result[j][i] = matrix[i][j]
    
    return result


# Problem 10: Matrix Multiplication
# Multiply two matrices
def matrix_multiply(A, B):
    """
    Time Complexity: O(m * n * p) where A is m×n and B is n×p
    Space Complexity: O(m * p)
    """
    m, n, p = len(A), len(B), len(B[0])
    result = [[0] * p for _ in range(m)]
    
    for i in range(m):
        for j in range(p):
            for k in range(n):
                result[i][j] += A[i][k] * B[k][j]
    
    return result


# Problem 11: Unique Paths
# Count unique paths from top-left to bottom-right
def unique_paths(m, n):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(n)
    """
    dp = [1] * n
    
    for i in range(1, m):
        for j in range(1, n):
            dp[j] += dp[j - 1]
    
    return dp[n - 1]


# Problem 12: Unique Paths II (with obstacles)
# Count unique paths with obstacles
def unique_paths_with_obstacles(obstacle_grid):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(n)
    """
    if not obstacle_grid or obstacle_grid[0][0] == 1:
        return 0
    
    m, n = len(obstacle_grid), len(obstacle_grid[0])
    dp = [0] * n
    dp[0] = 1
    
    for i in range(m):
        for j in range(n):
            if obstacle_grid[i][j] == 1:
                dp[j] = 0
            elif j > 0:
                dp[j] += dp[j - 1]
    
    return dp[n - 1]


# Problem 13: Minimum Path Sum
# Find minimum path sum from top-left to bottom-right
def min_path_sum(grid):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(n)
    """
    m, n = len(grid), len(grid[0])
    dp = [0] * n
    dp[0] = grid[0][0]
    
    # Initialize first row
    for j in range(1, n):
        dp[j] = dp[j - 1] + grid[0][j]
    
    # Fill rest of the grid
    for i in range(1, m):
        dp[0] += grid[i][0]
        for j in range(1, n):
            dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]
    
    return dp[n - 1]


# Problem 14: Word Search
# Search word in 2D grid
def word_search(board, word):
    """
    Time Complexity: O(m * n * 4^L) where L is word length
    Space Complexity: O(L)
    """
    m, n = len(board), len(board[0])
    
    def dfs(i, j, index):
        if index == len(word):
            return True
        
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index]:
            return False
        
        temp = board[i][j]
        board[i][j] = '#'  # Mark as visited
        
        found = (dfs(i + 1, j, index + 1) or
                dfs(i - 1, j, index + 1) or
                dfs(i, j + 1, index + 1) or
                dfs(i, j - 1, index + 1))
        
        board[i][j] = temp  # Restore
        return found
    
    for i in range(m):
        for j in range(n):
            if dfs(i, j, 0):
                return True
    
    return False


# Problem 15: Diagonal Traverse
# Traverse matrix diagonally
def find_diagonal_order(matrix):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(1) excluding output
    """
    if not matrix or not matrix[0]:
        return []
    
    m, n = len(matrix), len(matrix[0])
    result = []
    row, col = 0, 0
    direction = 1  # 1 for up-right, -1 for down-left
    
    for _ in range(m * n):
        result.append(matrix[row][col])
        
        # Calculate next position
        if direction == 1:
            if col == n - 1:
                row += 1
                direction = -1
            elif row == 0:
                col += 1
                direction = -1
            else:
                row -= 1
                col += 1
        else:
            if row == m - 1:
                col += 1
                direction = 1
            elif col == 0:
                row += 1
                direction = 1
            else:
                row += 1
                col -= 1
    
    return result


# Problem 16: Pascal's Triangle
# Generate Pascal's triangle
def generate_pascal_triangle(num_rows):
    """
    Time Complexity: O(num_rows^2)
    Space Complexity: O(num_rows^2)
    """
    triangle = []
    
    for i in range(num_rows):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(row)
    
    return triangle


# Problem 17: Sudoku Solver
# Solve valid Sudoku puzzle
def solve_sudoku(board):
    """
    Time Complexity: O(9^(m*n)) worst case
    Space Complexity: O(1)
    """
    def is_valid(row, col, num):
        for i in range(9):
            if board[i][col] == num or board[row][i] == num:
                return False
        
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if board[i][j] == num:
                    return False
        
        return True
    
    def solve():
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for num in '123456789':
                        if is_valid(i, j, num):
                            board[i][j] = num
                            if solve():
                                return True
                            board[i][j] = '.'
                    return False
        return True
    
    solve()


# Problem 18: Valid Sudoku
# Check if Sudoku board is valid
def is_valid_sudoku(board):
    """
    Time Complexity: O(1) - fixed 9x9 board
    Space Complexity: O(1)
    """
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]
    
    for i in range(9):
        for j in range(9):
            if board[i][j] != '.':
                num = board[i][j]
                box_index = (i // 3) * 3 + j // 3
                
                if num in rows[i] or num in cols[j] or num in boxes[box_index]:
                    return False
                
                rows[i].add(num)
                cols[j].add(num)
                boxes[box_index].add(num)
    
    return True


# Problem 19: Game of Life
# Simulate Conway's Game of Life
def game_of_life(board):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(1)
    """
    m, n = len(board), len(board[0])
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1),
                  (0, 1), (1, -1), (1, 0), (1, 1)]
    
    for i in range(m):
        for j in range(n):
            live_neighbors = 0
            
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n:
                    if board[ni][nj] == 1 or board[ni][nj] == -1:
                        live_neighbors += 1
            
            # Apply rules
            if board[i][j] == 1:
                if live_neighbors < 2 or live_neighbors > 3:
                    board[i][j] = -1  # Dies
            else:
                if live_neighbors == 3:
                    board[i][j] = 2  # Becomes alive
    
    # Update board
    for i in range(m):
        for j in range(n):
            if board[i][j] == -1:
                board[i][j] = 0
            elif board[i][j] == 2:
                board[i][j] = 1


# Problem 20: Matrix Diagonal Sum
# Calculate sum of matrix diagonals
def diagonal_sum(mat):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(mat)
    total = 0
    
    for i in range(n):
        total += mat[i][i]
        if i != n - 1 - i:
            total += mat[i][n - 1 - i]
    
    return total


# Test cases
if __name__ == "__main__":
    print("Problem 1 - Spiral Matrix:")
    matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(spiral_order(matrix1))  # [1, 2, 3, 6, 9, 8, 7, 4, 5]
    
    print("\nProblem 2 - Generate Spiral Matrix:")
    print(generate_spiral_matrix(3))
    
    print("\nProblem 3 - Rotate Matrix:")
    matrix2 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    rotate_matrix(matrix2)
    print(matrix2)
    
    print("\nProblem 5 - Search 2D Matrix:")
    matrix3 = [[1, 4, 7, 11], [2, 5, 8, 12], [3, 6, 9, 16], [10, 13, 14, 17]]
    print(search_matrix_2d(matrix3, 5))  # True
    
    print("\nProblem 9 - Transpose Matrix:")
    matrix4 = [[1, 2, 3], [4, 5, 6]]
    print(transpose(matrix4))
    
    print("\nProblem 11 - Unique Paths:")
    print(unique_paths(3, 7))  # 28
    
    print("\nProblem 13 - Minimum Path Sum:")
    grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
    print(min_path_sum(grid))  # 7
    
    print("\nProblem 15 - Diagonal Traverse:")
    matrix5 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(find_diagonal_order(matrix5))
    
    print("\nProblem 16 - Pascal's Triangle:")
    print(generate_pascal_triangle(5))
    
    print("\nProblem 20 - Matrix Diagonal Sum:")
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(diagonal_sum(mat))  # 25
