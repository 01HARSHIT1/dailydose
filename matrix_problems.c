#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Matrix DSA Interview Problems
 * Collection of common matrix problems with solutions
 */

// ==================== HELPER FUNCTIONS ====================

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("]\n");
    }
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// ==================== MATRIX PROBLEMS ====================

// Problem 1: Spiral Matrix
// Traverse matrix in spiral order
/**
 * Time Complexity: O(m * n)
 * Space Complexity: O(1) excluding output
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int m = matrixSize, n = matrixColSize[0];
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;
    int idx = 0;
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse right
        for (int i = left; i <= right; i++) {
            result[idx++] = matrix[top][i];
        }
        top++;
        
        // Traverse down
        for (int i = top; i <= bottom; i++) {
            result[idx++] = matrix[i][right];
        }
        right--;
        
        // Traverse left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[idx++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        // Traverse up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[idx++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}

// Problem 3: Rotate Image (90 degrees clockwise)
// Rotate matrix in-place by 90 degrees
/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    
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
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    bool firstRowZero = false;
    bool firstColZero = false;
    
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

// Problem 6: Search a 2D Matrix II
// Search in matrix where each row and column is sorted
/**
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }
    
    int m = matrixSize, n = matrixColSize[0];
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

// Problem 9: Transpose Matrix
// Transpose a matrix
/**
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
int** transposeMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = matrixColSize[0];
    int** result = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
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
int uniquePaths(int m, int n) {
    int* dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    
    int result = dp[n - 1];
    free(dp);
    return result;
}

// Problem 13: Minimum Path Sum
// Find minimum path sum from top-left to bottom-right
/**
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = grid[0][0];
    
    // Initialize first row
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    
    // Fill rest of the grid
    for (int i = 1; i < m; i++) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            dp[j] = (dp[j] < dp[j - 1] ? dp[j] : dp[j - 1]) + grid[i][j];
        }
    }
    
    int result = dp[n - 1];
    free(dp);
    return result;
}

// Problem 20: Matrix Diagonal Sum
// Calculate sum of matrix diagonals
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int diagonalSum(int** mat, int matSize, int* matColSize) {
    int n = matSize;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];
        if (i != n - 1 - i) {
            sum += mat[i][n - 1 - i];
        }
    }
    
    return sum;
}

// Test cases
int main() {
    printf("Problem 1 - Spiral Matrix:\n");
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* mat1[3];
    int cols1[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++) {
        mat1[i] = matrix1[i];
    }
    int returnSize1;
    int* result1 = spiralOrder(mat1, 3, cols1, &returnSize1);
    printArray(result1, returnSize1);
    free(result1);
    
    printf("\nProblem 3 - Rotate Matrix:\n");
    int matrix2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* mat2[3];
    int cols2[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++) {
        mat2[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            mat2[i][j] = matrix2[i][j];
        }
    }
    rotate(mat2, 3, cols2);
    printMatrix(mat2, 3, 3);
    for (int i = 0; i < 3; i++) {
        free(mat2[i]);
    }
    
    printf("\nProblem 6 - Search 2D Matrix II:\n");
    int matrix3[4][4] = {{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}};
    int* mat3[4];
    int cols3[4] = {4, 4, 4, 4};
    for (int i = 0; i < 4; i++) {
        mat3[i] = matrix3[i];
    }
    printf("%s\n", searchMatrix(mat3, 4, cols3, 5) ? "true" : "false");
    
    printf("\nProblem 11 - Unique Paths:\n");
    printf("%d\n", uniquePaths(3, 7)); // 28
    
    printf("\nProblem 13 - Minimum Path Sum:\n");
    int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int* gridPtr[3];
    int gridCols[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++) {
        gridPtr[i] = grid[i];
    }
    printf("%d\n", minPathSum(gridPtr, 3, gridCols)); // 7
    
    printf("\nProblem 20 - Matrix Diagonal Sum:\n");
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* matPtr[3];
    int matCols[3] = {3, 3, 3};
    for (int i = 0; i < 3; i++) {
        matPtr[i] = mat[i];
    }
    printf("%d\n", diagonalSum(matPtr, 3, matCols)); // 25
    
    return 0;
}
