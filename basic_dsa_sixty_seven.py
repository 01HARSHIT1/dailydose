"""
Basic DSA - Merge Intervals
Given a list of intervals [start, end], merge all overlapping intervals.
"""


def merge_intervals(intervals):
    """
    Sort by start time, then sweep and merge.
    Time Complexity: O(n log n)
    Space Complexity: O(n) for output (sort may use O(log n) stack)
    """
    if not intervals:
        return []

    ordered = sorted(intervals, key=lambda x: x[0])
    merged = [ordered[0]]

    for start, end in ordered[1:]:
        last_start, last_end = merged[-1]
        if start <= last_end:
            merged[-1] = [last_start, max(last_end, end)]
        else:
            merged.append([start, end])

    return merged


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Merge Intervals")
    print("=" * 60)

    tests = [
        ([[1, 3], [2, 6], [8, 10], [15, 18]], [[1, 6], [8, 10], [15, 18]]),
        ([[1, 4], [4, 5]], [[1, 5]]),
        ([[1, 4], [0, 4]], [[0, 4]]),
        ([], []),
    ]

    for intervals, expected in tests:
        got = merge_intervals(intervals)
        print(f"intervals={intervals} -> {got} (expected {expected})")
