"""
Basic DSA - Pascal's Triangle
Given an integer num_rows, return the first num_rows of Pascal's triangle.
"""


def generate_pascals_triangle(num_rows):
    """
    Build rows iteratively.
    Time Complexity: O(num_rows^2)
    Space Complexity: O(num_rows^2)
    """
    triangle = []
    for r in range(num_rows):
        row = [1] * (r + 1)
        for c in range(1, r):
            row[c] = triangle[r - 1][c - 1] + triangle[r - 1][c]
        triangle.append(row)
    return triangle


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Pascal's Triangle")
    print("=" * 60)

    print(generate_pascals_triangle(1))  # [[1]]
    print(generate_pascals_triangle(5))  # [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
