"""
Basic DSA - Merge Intervals
Given an array of intervals where intervals[i] = [start, end], merge all overlapping
intervals and return an array of the non-overlapping intervals that cover all intervals.
"""


def merge_intervals(intervals):
    """
    Sort by start and merge greedily.
    Time Complexity: O(n log n)
    Space Complexity: O(n) for output
    """
    if not intervals:
        return []
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0][:]]
    for s, e in intervals[1:]:
        last = merged[-1]
        if s <= last[1]:
            last[1] = max(last[1], e)
        else:
            merged.append([s, e])
    return merged


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Merge Intervals")
    print("=" * 60)

    print(merge_intervals([[1, 3], [2, 6], [8, 10], [15, 18]]))  # [[1,6],[8,10],[15,18]]
    print(merge_intervals([[1, 4], [4, 5]]))  # [[1,5]]
