/**
 * Basic DSA Problems - Minimum Genetic Mutation (LeetCode 433)
 * Min mutations from start to end; each step = 1 char change, must be in bank
 */
public class basic_dsa_four_hundred_thirty_three {

    // Problem: 8-char gene A/C/G/T. One mutation = one char change. BFS.

    /**
     * BFS: for each gene, try changing each pos to A/C/G/T.
     * Time O(8 * 4 * n) = O(n), Space O(n)
     */
    public static int minMutation(String start, String end, String[] bank) {
        java.util.Set<String> set = new java.util.HashSet<>(java.util.Arrays.asList(bank));
        if (!set.contains(end)) return -1;
        char[] genes = {'A','C','G','T'};
        java.util.Queue<String> q = new java.util.LinkedList<>();
        java.util.Set<String> vis = new java.util.HashSet<>();
        q.offer(start); vis.add(start);
        int steps = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                String s = q.poll();
                if (s.equals(end)) return steps;
                char[] arr = s.toCharArray();
                for (int j = 0; j < 8; j++) {
                    char old = arr[j];
                    for (char g : genes) {
                        if (g == old) continue;
                        arr[j] = g;
                        String next = new String(arr);
                        if (set.contains(next) && !vis.contains(next)) {
                            vis.add(next);
                            q.offer(next);
                        }
                    }
                    arr[j] = old;
                }
            }
            steps++;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Minimum Genetic Mutation");
        System.out.println("=".repeat(60));

        System.out.println("AACCGGTT->AACCGGTA, [AACCGGTA] -> " + minMutation("AACCGGTT", "AACCGGTA", new String[]{"AACCGGTA"}));
        System.out.println("AACCGGTT->AAACGGTA, bank -> " + minMutation("AACCGGTT", "AAACGGTA", new String[]{"AACCGGTA", "AACCGCTA", "AAACGGTA"}));
        System.out.println("AAAAACCC->AACCCCCC, bank -> " + minMutation("AAAAACCC", "AACCCCCC", new String[]{"AAAACCCC", "AAACCCCC", "AACCCCCC"}));
    }
}
