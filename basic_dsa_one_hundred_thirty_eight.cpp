/**
 * Basic DSA - Course Schedule (LeetCode 207)
 * Check if all courses can be finished (no cycle in DAG).
 */
#include <iostream>
#include <vector>
#include <queue>

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> indeg(numCourses, 0);
    std::vector<std::vector<int>> adj(numCourses);
    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        indeg[p[0]]++;
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indeg[i] == 0) q.push(i);
    int done = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        done++;
        for (int v : adj[u])
            if (--indeg[v] == 0) q.push(v);
    }
    return done == numCourses;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Course Schedule\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> pre1 = {{1,0}};
    std::cout << "2 courses, [[1,0]] -> " << (canFinish(2, pre1) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> pre2 = {{1,0}, {0,1}};
    std::cout << "2 courses, [[1,0],[0,1]] -> " << (canFinish(2, pre2) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> pre3 = {{1,0}, {2,0}, {3,1}, {3,2}};
    std::cout << "4 courses, [[1,0],[2,0],[3,1],[3,2]] -> " << (canFinish(4, pre3) ? "true" : "false") << "\n";
}
