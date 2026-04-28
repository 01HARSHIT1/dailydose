"""
Basic DSA - Non-overlapping Intervals
Given an array of intervals intervals where intervals[i] = [start, end],
return the minimum number of intervals you need to remove to make the rest of the
intervals non-overlapping.
"""


def erase_overlap_intervals(intervals):
    """
    Greedy: sort by end time, keep intervals with earliest finishing time.
    Time Complexity: O(n log n)
    Space Complexity: O(1) extra
    """
    if not intervals:
        return 0
    intervals.sort(key=lambda x: x[1])
    removals = 0
    prev_end = intervals[0][1]
    for s, e in intervals[1:]:
        if s < prev_end:
            removals += 1
        else:
            prev_end = e
    return removals


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Non-overlapping Intervals")
    print("=" * 60)

    print(erase_overlap_intervals([[1, 2], [2, 3], [3, 4], [1, 3]]))  # 1
    print(erase_overlap_intervals([[1, 2], [1, 2], [1, 2]]))  # 2
    print(erase_overlap_intervals([[1, 2], [2, 3]]))  # 0
