"""
Basic DSA - Minimum Number of Arrows to Burst Balloons
There are some spherical balloons spread in 2D space. For each balloon, its horizontal
diameter is represented as [x_start, x_end]. An arrow can be shot vertically at x and
bursts all balloons with x_start <= x <= x_end.
Return the minimum number of arrows needed to burst all balloons.
"""


def find_min_arrow_shots(points):
    """
    Greedy by sorting intervals by end.
    Time Complexity: O(n log n)
    Space Complexity: O(1) extra
    """
    if not points:
        return 0
    points.sort(key=lambda p: p[1])
    arrows = 1
    end = points[0][1]
    for s, e in points[1:]:
        if s > end:
            arrows += 1
            end = e
    return arrows


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Minimum Arrows to Burst Balloons")
    print("=" * 60)

    print(find_min_arrow_shots([[10, 16], [2, 8], [1, 6], [7, 12]]))  # 2
    print(find_min_arrow_shots([[1, 2], [3, 4], [5, 6], [7, 8]]))  # 4
    print(find_min_arrow_shots([[1, 2], [2, 3], [3, 4], [4, 5]]))  # 2
