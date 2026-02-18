/**
 * Basic DSA Problems - Flatten Nested List Iterator (LeetCode 341)
 * Iterator that flattens nested list structure
 */
public class basic_dsa_three_hundred_forty_one {

    // Problem: Nested list. Implement NestedIterator with next() and hasNext().

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

    static class NestedIterator {
        private java.util.Iterator<Integer> it;

        public NestedIterator(java.util.List<NestedInteger> nestedList) {
            java.util.List<Integer> flat = new java.util.ArrayList<>();
            flatten(nestedList, flat);
            it = flat.iterator();
        }

        private void flatten(java.util.List<NestedInteger> list, java.util.List<Integer> out) {
            for (NestedInteger ni : list) {
                if (ni.isInteger()) out.add(ni.getInteger());
                else flatten(ni.getList(), out);
            }
        }

        public boolean hasNext() { return it.hasNext(); }
        public Integer next() { return it.next(); }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Flatten Nested List Iterator");
        System.out.println("=".repeat(60));

        java.util.List<NestedInteger> list = java.util.Arrays.asList(
            new NestedInt(1),
            new NestedInt(java.util.Arrays.asList(new NestedInt(2), new NestedInt(java.util.Arrays.asList(new NestedInt(3)))))
        );
        NestedIterator it = new NestedIterator(list);
        java.util.List<Integer> out = new java.util.ArrayList<>();
        while (it.hasNext()) out.add(it.next());
        System.out.println("[1,[2,[3]]] -> " + out);
    }
}
