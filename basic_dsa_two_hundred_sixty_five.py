"""
Basic DSA - Evaluate Division
You are given equations in the form A / B = value, and queries.
Return the result of each query. If it cannot be determined, return -1.0.
"""


from collections import defaultdict, deque


def calc_equation(equations, values, queries):
    """
    Build a weighted graph and BFS per query.
    Time Complexity: O(E + Q*(V+E)) in worst case
    Space Complexity: O(V + E)
    """
    g = defaultdict(list)
    for (a, b), v in zip(equations, values):
        g[a].append((b, v))
        g[b].append((a, 1.0 / v))

    def bfs(src, dst):
        if src not in g or dst not in g:
            return -1.0
        if src == dst:
            return 1.0
        q = deque([(src, 1.0)])
        seen = {src}
        while q:
            node, acc = q.popleft()
            for nei, w in g[node]:
                if nei in seen:
                    continue
                nxt = acc * w
                if nei == dst:
                    return nxt
                seen.add(nei)
                q.append((nei, nxt))
        return -1.0

    return [bfs(a, b) for a, b in queries]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Evaluate Division")
    print("=" * 60)

    eq = [["a", "b"], ["b", "c"]]
    vals = [2.0, 3.0]
    qs = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
    print(calc_equation(eq, vals, qs))  # [6.0, 0.5, -1.0, 1.0, -1.0]
