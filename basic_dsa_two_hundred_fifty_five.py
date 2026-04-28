"""
Basic DSA - Insert Interval
You are given an array of non-overlapping intervals sorted by start time and a new interval.
Insert the new interval into the intervals (merge if necessary) and return the result.
"""


def insert_interval(intervals, new_interval):
    """
    Linear scan with merging.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    res = []
    i = 0
    n = len(intervals)
    start, end = new_interval

    while i < n and intervals[i][1] < start:
        res.append(intervals[i])
        i += 1

    while i < n and intervals[i][0] <= end:
        start = min(start, intervals[i][0])
        end = max(end, intervals[i][1])
        i += 1
    res.append([start, end])

    while i < n:
        res.append(intervals[i])
        i += 1
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Insert Interval")
    print("=" * 60)

    print(insert_interval([[1, 3], [6, 9]], [2, 5]))  # [[1,5],[6,9]]
    print(insert_interval([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [4, 8]))  # [[1,2],[3,10],[12,16]]
