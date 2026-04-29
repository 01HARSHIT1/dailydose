"""
Basic DSA - Sparse Matrix Multiplication
Given two sparse matrices mat1 (m x k) and mat2 (k x n), return mat1 * mat2.
"""


def multiply_sparse(mat1, mat2):
    """
    Iterate only non-zero entries.
    Time Complexity: O(nnz(mat1) * avg_nonzero_per_row_in_mat2)
    Space Complexity: O(m*n) for result
    """
    m, k = len(mat1), len(mat1[0])
    n = len(mat2[0])
    res = [[0] * n for _ in range(m)]

    # Precompute non-zero columns for each row of mat2
    mat2_nz = []
    for r in range(k):
        row_nz = []
        for c, v in enumerate(mat2[r]):
            if v != 0:
                row_nz.append((c, v))
        mat2_nz.append(row_nz)

    for i in range(m):
        for t, a in enumerate(mat1[i]):
            if a == 0:
                continue
            for j, b in mat2_nz[t]:
                res[i][j] += a * b

    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Sparse Matrix Multiplication")
    print("=" * 60)

    mat1 = [[1, 0, 0], [-1, 0, 3]]
    mat2 = [[7, 0, 0], [0, 0, 0], [0, 0, 1]]
    print(multiply_sparse(mat1, mat2))  # [[7,0,0],[-7,0,3]]
