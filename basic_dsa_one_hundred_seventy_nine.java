/**
 * Basic DSA Problems - Course Schedule
 * Check if all courses can be finished (no cycle in dependency graph)
 */
import java.util.*;

public class basic_dsa_one_hundred_seventy_nine {

    // Problem: numCourses courses, prerequisites[i] = [a,b] means b must be done before a. Return true if possible.

    /**
     * Build graph (b -> a), run DFS to detect cycle. 0=unvisited, 1=visiting, 2=done.
     * Time O(V+E), Space O(V+E)
     */
    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] adj = new List[numCourses];
        for (int i = 0; i < numCourses; i++) adj[i] = new ArrayList<>();
        for (int[] e : prerequisites) adj[e[1]].add(e[0]);
        int[] state = new int[numCourses];
        for (int i = 0; i < numCourses; i++)
            if (hasCycle(i, adj, state)) return false;
        return true;
    }

    static boolean hasCycle(int u, List<Integer>[] adj, int[] state) {
        if (state[u] == 1) return true;
        if (state[u] == 2) return false;
        state[u] = 1;
        for (int v : adj[u])
            if (hasCycle(v, adj, state)) return true;
        state[u] = 2;
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Course Schedule");
        System.out.println("=".repeat(60));

        System.out.println("2, [[1,0]] -> " + canFinish(2, new int[][]{{1, 0}}));
        System.out.println("2, [[1,0],[0,1]] -> " + canFinish(2, new int[][]{{1, 0}, {0, 1}}));
    }
}
