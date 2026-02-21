/**
 * Basic DSA Problems - Insert Delete GetRandom O(1) (LeetCode 380)
 * insert, remove, getRandom in O(1) average
 */
public class basic_dsa_three_hundred_eighty {

    // Problem: insert(val), remove(val), getRandom() in O(1) avg.

    static class RandomizedSet {
        java.util.Map<Integer, Integer> idx = new java.util.HashMap<>();
        java.util.List<Integer> list = new java.util.ArrayList<>();

        public boolean insert(int val) {
            if (idx.containsKey(val)) return false;
            idx.put(val, list.size());
            list.add(val);
            return true;
        }

        public boolean remove(int val) {
            if (!idx.containsKey(val)) return false;
            int i = idx.get(val);
            int last = list.get(list.size() - 1);
            list.set(i, last);
            idx.put(last, i);
            list.remove(list.size() - 1);
            idx.remove(val);
            return true;
        }

        public int getRandom() {
            return list.get(new java.util.Random().nextInt(list.size()));
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Insert Delete GetRandom O(1)");
        System.out.println("=".repeat(60));

        RandomizedSet rs = new RandomizedSet();
        System.out.println("insert(1)=" + rs.insert(1) + " insert(2)=" + rs.insert(2)
                + " remove(1)=" + rs.remove(1) + " insert(2)=" + rs.insert(2));
    }
}
