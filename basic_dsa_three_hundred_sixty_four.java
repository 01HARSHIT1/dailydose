/**
 * Basic DSA Problems - Nested List Weight Sum II (LeetCode 364)
 * Sum = integer * (maxDepth - depth + 1); deeper = higher weight
 */
public class basic_dsa_three_hundred_sixty_four {

    // Problem: Nested list. Weight by reverse depth (deeper = heavier).

    interface NestedInteger {
        boolean isInteger();
        Integer getInteger();
        java.util.List<NestedInteger> getList();
    }

    static class NestedInt implements NestedInteger {
        Integer val;
        java.util.List<NestedInteger> list;
        NestedInt(int v) { val = v; list = null; }
        NestedInt(java.util.List<NestedInteger> l) { val = null; list = l; }
        public boolean isInteger() { return val != null; }
        public Integer getInteger() { return val; }
        public java.util.List<NestedInteger> getList() { return list; }
    }

    /**
     * Two-pass: get maxDepth, then sum each integer * (maxDepth - depth + 1).
     * Time O(n), Space O(d)
     */
    public static int depthSumInverse(java.util.List<NestedInteger> nestedList) {
        int maxD = maxDepth(nestedList, 1);
        return sum(nestedList, 1, maxD);
    }

    private static int maxDepth(java.util.List<NestedInteger> list, int d) {
        int max = d;
        for (NestedInteger ni : list)
            if (!ni.isInteger()) max = Math.max(max, maxDepth(ni.getList(), d + 1));
        return max;
    }

    private static int sum(java.util.List<NestedInteger> list, int d, int maxD) {
        int s = 0;
        for (NestedInteger ni : list) {
            if (ni.isInteger()) s += ni.getInteger() * (maxD - d + 1);
            else s += sum(ni.getList(), d + 1, maxD);
        }
        return s;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Nested List Weight Sum II");
        System.out.println("=".repeat(60));

        java.util.List<NestedInteger> a = java.util.Arrays.asList(
            new NestedInt(1),
            new NestedInt(java.util.Arrays.asList(new NestedInt(4), new NestedInt(java.util.Arrays.asList(new NestedInt(6)))))
        );
        System.out.println("[1,[4,[6]]] -> " + depthSumInverse(a));
    }
}
