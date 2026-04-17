"""
Basic DSA - Course Schedule (Detect Cycle in Directed Graph)
Given numCourses and prerequisites [a, b] meaning b -> a, return True if you can finish all courses.
"""

from collections import deque


def can_finish(num_courses, prerequisites):
    """
    Kahn's algorithm (topological sort) using indegrees.
    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
    """
    adj = [[] for _ in range(num_courses)]
    indeg = [0] * num_courses

    for a, b in prerequisites:
        adj[b].append(a)
        indeg[a] += 1

    q = deque([i for i in range(num_courses) if indeg[i] == 0])
    taken = 0

    while q:
        u = q.popleft()
        taken += 1
        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)

    return taken == num_courses


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Course Schedule")
    print("=" * 60)

    print(can_finish(2, [[1, 0]]))  # True
    print(can_finish(2, [[1, 0], [0, 1]]))  # False
    print(can_finish(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # True

