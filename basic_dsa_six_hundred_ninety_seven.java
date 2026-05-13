import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Basic DSA Problems - One Fundamental Graph DFS Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_ninety_seven {

    // Problem 1: All Paths From Source to Target
    // DAG: n nodes 0..n-1; graph[i] lists neighbors i -> v. List every path 0 to n-1.

    private static boolean valid(int[][] graph) {
        int n = graph.length;
        for (int i = 0; i < n; i++) {
            if (graph[i] == null) {
                return false;
            }
            for (int v : graph[i]) {
                if (v < 0 || v >= n) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void dfs(int[][] graph, int u, int goal, List<Integer> path, List<List<Integer>> out) {
        if (u == goal) {
            out.add(new ArrayList<>(path));
            return;
        }
        for (int v : graph[u]) {
            path.add(v);
            dfs(graph, v, goal, path, out);
            path.remove(path.size() - 1);
        }
    }

    /**
     * Backtracking DFS from 0.
     * Time Complexity: O(2^n * n) worst case paths
     * Space Complexity: O(n) recursion + path
     */
    public static List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        if (graph == null) {
            return null;
        }
        if (!valid(graph)) {
            return null;
        }

        int n = graph.length;
        List<List<Integer>> out = new ArrayList<>();
        if (n == 0) {
            return out;
        }

        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(graph, 0, n - 1, path, out);
        return out;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: All Paths From Source to Target");
        System.out.println("=".repeat(60));

        int[][] a = {{1, 2}, {3}, {3}, {}};
        System.out.println("4-node sample -> " + allPathsSourceTarget(a));

        int[][] b = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
        System.out.println("5-node sample -> " + allPathsSourceTarget(b));

        int[][] c = {{1}, {}};
        System.out.println("two nodes -> " + allPathsSourceTarget(c));

        System.out.println("null -> " + (allPathsSourceTarget(null) == null ? "null" : "error"));

        int[][] bad = {{1, 5}, {}};
        System.out.println("invalid edge -> " + (allPathsSourceTarget(bad) == null ? "null" : "error"));
    }
}
