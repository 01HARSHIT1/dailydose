/**
 * Basic DSA Problems - Sequence Reconstruction (LeetCode 444)
 * Check if org is the unique shortest supersequence of all seqs
 */
public class basic_dsa_four_hundred_forty_four {

    // Problem: org, seqs. Topo sort from seqs; unique order must equal org.

    /**
     * Build DAG from consecutive pairs in seqs. Topo sort; queue size>1 => not unique.
     * Time O(V+E), Space O(V+E)
     */
    public static boolean sequenceReconstruction(int[] org, java.util.List<java.util.List<Integer>> seqs) {
        if (seqs.isEmpty()) return false;
        int n = org.length;
        java.util.List<java.util.Set<Integer>> graph = new java.util.ArrayList<>();
        int[] inDeg = new int[n];
        for (int i = 0; i < n; i++) graph.add(new java.util.HashSet<>());
        for (java.util.List<Integer> seq : seqs) {
            for (int x : seq) if (x < 1 || x > n) return false;
            for (int i = 0; i + 1 < seq.size(); i++) {
                int u = seq.get(i) - 1, v = seq.get(i + 1) - 1;
                if (graph.get(u).add(v)) inDeg[v]++;
            }
        }
        java.util.Queue<Integer> q = new java.util.LinkedList<>();
        for (int i = 0; i < n; i++) if (inDeg[i] == 0) q.offer(i);
        int idx = 0;
        while (!q.isEmpty()) {
            if (q.size() > 1) return false;
            int u = q.poll();
            if (org[idx++] - 1 != u) return false;
            for (int v : graph.get(u))
                if (--inDeg[v] == 0) q.offer(v);
        }
        return idx == n;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sequence Reconstruction");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3], [[1,2],[1,3]] -> " + sequenceReconstruction(new int[]{1,2,3}, java.util.Arrays.asList(java.util.Arrays.asList(1,2), java.util.Arrays.asList(1,3))));
        System.out.println("[1,2,3], [[1,2]] -> " + sequenceReconstruction(new int[]{1,2,3}, java.util.Arrays.asList(java.util.Arrays.asList(1,2))));
        System.out.println("[1,2,3], [[1,2],[1,3],[2,3]] -> " + sequenceReconstruction(new int[]{1,2,3}, java.util.Arrays.asList(java.util.Arrays.asList(1,2), java.util.Arrays.asList(1,3), java.util.Arrays.asList(2,3))));
    }
}
