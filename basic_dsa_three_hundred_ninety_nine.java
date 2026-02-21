/**
 * Basic DSA Problems - Evaluate Division (LeetCode 399)
 * equations a/b=k, queries c/d -> c/d value or -1
 */
public class basic_dsa_three_hundred_ninety_nine {

    // Problem: equations [[a,b],...], values. queries [[c,d],...]. Return c/d or -1.

    /**
     * Build graph: a->b with weight k, b->a with 1/k. DFS/BFS for each query.
     * Time O(q * (v+e)), Space O(v+e)
     */
    public static double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        java.util.Map<String, java.util.Map<String, Double>> g = new java.util.HashMap<>();
        for (int i = 0; i < equations.length; i++) {
            String a = equations[i][0], b = equations[i][1];
            g.computeIfAbsent(a, k -> new java.util.HashMap<>()).put(b, values[i]);
            g.computeIfAbsent(b, k -> new java.util.HashMap<>()).put(a, 1.0 / values[i]);
        }
        double[] out = new double[queries.length];
        for (int i = 0; i < queries.length; i++)
            out[i] = dfs(g, queries[i][0], queries[i][1], new java.util.HashSet<>());
        return out;
    }

    private static double dfs(java.util.Map<String, java.util.Map<String, Double>> g,
            String cur, String target, java.util.Set<String> vis) {
        if (!g.containsKey(cur) || !g.containsKey(target)) return -1.0;
        if (cur.equals(target)) return 1.0;
        vis.add(cur);
        for (java.util.Map.Entry<String, Double> e : g.get(cur).entrySet()) {
            if (vis.contains(e.getKey())) continue;
            double v = dfs(g, e.getKey(), target, vis);
            if (v > 0) return e.getValue() * v;
        }
        vis.remove(cur);
        return -1.0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Evaluate Division");
        System.out.println("=".repeat(60));

        String[][] eq = {{"a","b"},{"b","c"}};
        double[] vals = {2.0, 3.0};
        String[][] q = {{"a","c"},{"b","a"},{"a","e"}};
        System.out.println("a/c,b/a,a/e -> " + java.util.Arrays.toString(calcEquation(eq, vals, q)));
    }
}
