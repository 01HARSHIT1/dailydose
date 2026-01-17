import java.util.*;

/**
 * Matrix DSA Interview Problems
 * Collection of common matrix problems with solutions
 */
public class matrix_problems {
    
    // Problem 1: Spiral Matrix
    // Traverse matrix in spiral order
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(1) excluding output
     */
    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix.length == 0 || matrix[0].length == 0) {
            return result;
        }
        
        int top = 0, bottom = matrix.length - 1;
        int left = 0, right = matrix[0].length - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse right
            for (int i = left; i <= right; i++) {
                result.add(matrix[top][i]);
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom; i++) {
                result.add(matrix[i][right]);
            }
            right--;
            
            // Traverse left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.add(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // Traverse up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.add(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
    
    // Problem 2: Spiral Matrix II
    // Generate spiral matrix filled with numbers 1 to n^2
    /**
     * Time Complexity: O(n^2)
     * Space Complexity: O(n^2)
     */
    public static int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int num = 1;
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Fill right
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;
            
            // Fill down
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;
            
            // Fill left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }
            
            // Fill up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
    
    // Problem 3: Rotate Image (90 degrees clockwise)
    // Rotate matrix in-place by 90 degrees
    /**
     * Time Complexity: O(n^2)
     * Space Complexity: O(1)
     */
    public static void rotate(int[][] matrix) {
        int n = matrix.length;
        
        // Transpose matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    }
    
    // Problem 4: Set Matrix Zeros
    // Set entire row and column to zero if element is zero
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(1)
     */
    public static void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean firstRowZero = false;
        boolean firstColZero = false;
        
        // Check first row
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Check first column
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Mark zeros in first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set zeros based on marks
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Set first column
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
    
    // Problem 5: Search a 2D Matrix
    // Search target in sorted matrix
    /**
     * Time Complexity: O(log(m * n))
     * Space Complexity: O(1)
     */
    public static boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
    
    // Problem 6: Search a 2D Matrix II
    // Search in matrix where each row and column is sorted
    /**
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static boolean searchMatrixII(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        int m = matrix.length, n = matrix[0].length;
        int row = 0, col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        
        return false;
    }
    
    // Problem 7: Number of Islands
    // Count number of islands (connected 1s) in matrix
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(m * n)
     */
    public static int numIslands(char[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        
        int m = grid.length, n = grid[0].length;
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        return count;
    }
    
    private static void dfs(char[][] grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0'; // Mark as visited
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }
    
    // Problem 8: Max Area of Island
    // Find maximum area of island in binary matrix
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(m * n)
     */
    public static int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        
        int m = grid.length, n = grid[0].length;
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = Math.max(maxArea, dfsArea(grid, i, j, m, n));
                }
            }
        }
        
        return maxArea;
    }
    
    private static int dfsArea(int[][] grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0; // Mark as visited
        return 1 + dfsArea(grid, i + 1, j, m, n) +
                   dfsArea(grid, i - 1, j, m, n) +
                   dfsArea(grid, i, j + 1, m, n) +
                   dfsArea(grid, i, j - 1, m, n);
    }
    
    // Problem 9: Transpose Matrix
    // Transpose a matrix
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(m * n)
     */
    public static int[][] transpose(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] result = new int[n][m];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        
        return result;
    }
    
    // Problem 10: Matrix Multiplication
    // Multiply two matrices
    /**
     * Time Complexity: O(m * n * p)
     * Space Complexity: O(m * p)
     */
    public static int[][] matrixMultiply(int[][] A, int[][] B) {
        int m = A.length, n = B.length, p = B[0].length;
        int[][] result = new int[m][p];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return result;
    }
    
    // Problem 11: Unique Paths
    // Count unique paths from top-left to bottom-right
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(n)
     */
    public static int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
    
    // Problem 12: Unique Paths II (with obstacles)
    // Count unique paths with obstacles
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(n)
     */
    public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid.length == 0 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[] dp = new int[n];
        dp[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n - 1];
    }
    
    // Problem 13: Minimum Path Sum
    // Find minimum path sum from top-left to bottom-right
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(n)
     */
    public static int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] dp = new int[n];
        dp[0] = grid[0][0];
        
        // Initialize first row
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        
        // Fill rest of the grid
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = Math.min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        
        return dp[n - 1];
    }
    
    // Problem 14: Word Search
    // Search word in 2D grid
    /**
     * Time Complexity: O(m * n * 4^L)
     * Space Complexity: O(L)
     */
    public static boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfsWord(board, word, i, j, 0, m, n)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    private static boolean dfsWord(char[][] board, String word, int i, int j, int index, int m, int n) {
        if (index == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word.charAt(index)) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited
        
        boolean found = dfsWord(board, word, i + 1, j, index + 1, m, n) ||
                       dfsWord(board, word, i - 1, j, index + 1, m, n) ||
                       dfsWord(board, word, i, j + 1, index + 1, m, n) ||
                       dfsWord(board, word, i, j - 1, index + 1, m, n);
        
        board[i][j] = temp; // Restore
        return found;
    }
    
    // Problem 15: Diagonal Traverse
    // Traverse matrix diagonally
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(1) excluding output
     */
    public static int[] findDiagonalOrder(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return new int[0];
        }
        
        int m = matrix.length, n = matrix[0].length;
        int[] result = new int[m * n];
        int row = 0, col = 0;
        int direction = 1; // 1 for up-right, -1 for down-left
        
        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];
            
            if (direction == 1) {
                if (col == n - 1) {
                    row++;
                    direction = -1;
                } else if (row == 0) {
                    col++;
                    direction = -1;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                    direction = 1;
                } else if (col == 0) {
                    row++;
                    direction = 1;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
    
    // Problem 16: Pascal's Triangle
    // Generate Pascal's triangle
    /**
     * Time Complexity: O(numRows^2)
     * Space Complexity: O(numRows^2)
     */
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(triangle.get(i - 1).get(j - 1) + triangle.get(i - 1).get(j));
                }
            }
            triangle.add(row);
        }
        
        return triangle;
    }
    
    // Problem 20: Matrix Diagonal Sum
    // Calculate sum of matrix diagonals
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int diagonalSum(int[][] mat) {
        int n = mat.length;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            if (i != n - 1 - i) {
                sum += mat[i][n - 1 - i];
            }
        }
        
        return sum;
    }
    
    // Helper methods for printing
    private static void printList(List<Integer> list) {
        System.out.println(list);
    }
    
    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("Problem 1 - Spiral Matrix:");
        int[][] matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        printList(spiralOrder(matrix1));
        
        System.out.println("\nProblem 2 - Generate Spiral Matrix:");
        printMatrix(generateMatrix(3));
        
        System.out.println("\nProblem 5 - Search 2D Matrix:");
        int[][] matrix2 = {{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}};
        System.out.println(searchMatrixII(matrix2, 5)); // true
        
        System.out.println("\nProblem 9 - Transpose Matrix:");
        int[][] matrix3 = {{1, 2, 3}, {4, 5, 6}};
        printMatrix(transpose(matrix3));
        
        System.out.println("\nProblem 11 - Unique Paths:");
        System.out.println(uniquePaths(3, 7)); // 28
        
        System.out.println("\nProblem 13 - Minimum Path Sum:");
        int[][] grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        System.out.println(minPathSum(grid)); // 7
        
        System.out.println("\nProblem 16 - Pascal's Triangle:");
        System.out.println(generate(5));
        
        System.out.println("\nProblem 20 - Matrix Diagonal Sum:");
        int[][] mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        System.out.println(diagonalSum(mat)); // 25
    }
}
