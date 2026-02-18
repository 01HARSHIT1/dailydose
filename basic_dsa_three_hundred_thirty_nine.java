/**
 * Basic DSA Problems - Nested List Weight Sum (LeetCode 339)
 * Sum integers weighted by depth in nested structure
 */
public class basic_dsa_three_hundred_thirty_nine {

    // Problem: Nested list. Sum = each integer * its depth. Root list depth = 1.

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
     * DFS with depth. Add integer * depth when integer, recurse on list.
     * Time O(n), Space O(d) recursion
     */
    public static int depthSum(java.util.List<NestedInteger> nestedList) {
        return dfs(nestedList, 1);
    }

    private static int dfs(java.util.List<NestedInteger> list, int d) {
        int sum = 0;
        for (NestedInteger ni : list) {
            if (ni.isInteger()) sum += ni.getInteger() * d;
            else sum += dfs(ni.getList(), d + 1);
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Nested List Weight Sum");
        System.out.println("=".repeat(60));

        java.util.List<NestedInteger> a = java.util.Arrays.asList(
            new NestedInt(1),
            new NestedInt(java.util.Arrays.asList(new NestedInt(2), new NestedInt(java.util.Arrays.asList(new NestedInt(3)))))
        );
        System.out.println("[[1,1],2,[1,1]] style -> " + depthSum(a));

        java.util.List<NestedInteger> b = java.util.Arrays.asList(new NestedInt(1), new NestedInt(java.util.Arrays.asList(new NestedInt(4), new NestedInt(java.util.Arrays.asList(new NestedInt(6))))));
        System.out.println("[1,[4,[6]]] -> " + depthSum(b));
    }
}
