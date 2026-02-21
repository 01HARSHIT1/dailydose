/**
 * Basic DSA Problems - Mini Parser (LeetCode 385)
 * Parse nested list string to NestedInteger
 */
public class basic_dsa_three_hundred_eighty_five {

    // Problem: Parse "[123,[456,[789]]]" style string to NestedInteger.

    interface NestedInteger {
        boolean isInteger();
        Integer getInteger();
        void setInteger(int value);
        void add(NestedInteger ni);
        java.util.List<NestedInteger> getList();
    }

    static class NestedInt implements NestedInteger {
        Integer val;
        java.util.List<NestedInteger> list;

        NestedInt() { list = new java.util.ArrayList<>(); }
        NestedInt(int v) { val = v; }

        public boolean isInteger() { return val != null; }
        public Integer getInteger() { return val; }
        public void setInteger(int value) { val = value; }
        public void add(NestedInteger ni) { list.add(ni); }
        public java.util.List<NestedInteger> getList() { return list; }
    }

    /**
     * Recursive descent: '[' starts list, digits parse integer, ']' ends.
     * Time O(n), Space O(d)
     */
    public static NestedInteger deserialize(String s) {
        int[] i = {0};
        return parse(s, i);
    }

    private static NestedInteger parse(String s, int[] i) {
        if (s.charAt(i[0]) == '[') {
            i[0]++;
            NestedInteger ni = new NestedInt();
            while (i[0] < s.length() && s.charAt(i[0]) != ']') {
                if (s.charAt(i[0]) == ',') i[0]++;
                ni.add(parse(s, i));
            }
            i[0]++;
            return ni;
        }
        int sign = 1;
        if (s.charAt(i[0]) == '-') { sign = -1; i[0]++; }
        int num = 0;
        while (i[0] < s.length() && Character.isDigit(s.charAt(i[0])))
            num = num * 10 + (s.charAt(i[0]++) - '0');
        return new NestedInt(sign * num);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Mini Parser");
        System.out.println("=".repeat(60));

        NestedInteger a = deserialize("324");
        System.out.println("324 -> " + (a.isInteger() ? a.getInteger() : "list"));
        NestedInteger b = deserialize("[123,[456,[789]]]");
        System.out.println("[123,[456,[789]]] -> parsed");
    }
}
