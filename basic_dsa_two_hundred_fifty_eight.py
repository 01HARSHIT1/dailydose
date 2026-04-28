"""
Basic DSA - Meeting Rooms II
Given an array of meeting time intervals intervals where intervals[i] = [start, end],
return the minimum number of conference rooms required.
"""


def min_meeting_rooms(intervals):
    """
    Sweep line over sorted starts/ends.
    Time Complexity: O(n log n)
    Space Complexity: O(n)
    """
    if not intervals:
        return 0
    starts = sorted(i[0] for i in intervals)
    ends = sorted(i[1] for i in intervals)
    s = e = 0
    rooms = best = 0
    while s < len(starts):
        if starts[s] < ends[e]:
            rooms += 1
            best = max(best, rooms)
            s += 1
        else:
            rooms -= 1
            e += 1
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Meeting Rooms II")
    print("=" * 60)

    print(min_meeting_rooms([[0, 30], [5, 10], [15, 20]]))  # 2
    print(min_meeting_rooms([[7, 10], [2, 4]]))  # 1
