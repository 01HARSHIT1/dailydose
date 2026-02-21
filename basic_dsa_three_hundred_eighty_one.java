/**
 * Basic DSA Problems - Insert Delete GetRandom O(1) - Duplicates (LeetCode 381)
 * insert, remove, getRandom with duplicates in O(1) average
 */
public class basic_dsa_three_hundred_eighty_one {

    // Problem: Same as 380 but duplicates allowed. O(1) avg for each op.

    static class RandomizedCollection {
        java.util.Map<Integer, java.util.Set<Integer>> idx = new java.util.HashMap<>();
        java.util.List<Integer> list = new java.util.ArrayList<>();

        public boolean insert(int val) {
            boolean had = idx.containsKey(val);
            idx.computeIfAbsent(val, k -> new java.util.HashSet<>()).add(list.size());
            list.add(val);
            return !had;
        }

        public boolean remove(int val) {
            if (!idx.containsKey(val) || idx.get(val).isEmpty()) return false;
            int i = idx.get(val).iterator().next();
            idx.get(val).remove(i);
            int last = list.get(list.size() - 1);
            list.set(i, last);
            idx.get(last).remove(list.size() - 1);
            idx.get(last).add(i);
            list.remove(list.size() - 1);
            if (idx.get(val).isEmpty()) idx.remove(val);
            return true;
        }

        public int getRandom() {
            return list.get(new java.util.Random().nextInt(list.size()));
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Insert Delete GetRandom O(1) - Duplicates");
        System.out.println("=".repeat(60));

        RandomizedCollection rc = new RandomizedCollection();
        System.out.println("insert(1)=" + rc.insert(1) + " insert(1)=" + rc.insert(1)
                + " insert(2)=" + rc.insert(2) + " remove(1)=" + rc.remove(1));
    }
}
