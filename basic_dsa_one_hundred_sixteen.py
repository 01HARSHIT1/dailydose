"""
Basic DSA - Flood Fill
Given an image (2D array), flood fill from (sr, sc) changing connected pixels of the starting color
to a new color. Connectivity is 4-directional.
"""


def flood_fill(image, sr, sc, color):
    """
    DFS fill; avoid infinite recursion by checking if new color equals start.
    Time Complexity: O(rows * cols)
    Space Complexity: O(rows * cols) recursion stack worst case
    """
    if not image or not image[0]:
        return image

    start = image[sr][sc]
    if start == color:
        return image

    rows, cols = len(image), len(image[0])

    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or image[r][c] != start:
            return
        image[r][c] = color
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)

    dfs(sr, sc)
    return image


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Flood Fill")
    print("=" * 60)

    img = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
    print(flood_fill([row[:] for row in img], 1, 1, 2))  # [[2,2,2],[2,2,0],[2,0,1]]
    print(flood_fill([[0, 0, 0], [0, 0, 0]], 0, 0, 0))  # unchanged

