/**
 * Basic DSA Problems - LFU Cache (LeetCode 460)
 * get/put O(1). Evict LFU; on tie evict LRU.
 */
public class basic_dsa_four_hundred_sixty {

    static class LFUCache {
        int cap, minFreq = 0;
        java.util.Map<Integer, Integer> kv = new java.util.HashMap<>();
        java.util.Map<Integer, Integer> kf = new java.util.HashMap<>();
        java.util.Map<Integer, java.util.LinkedHashSet<Integer>> fk = new java.util.HashMap<>();

        LFUCache(int capacity) { cap = capacity; }

        public int get(int key) {
            if (!kv.containsKey(key)) return -1;
            int freq = kf.get(key);
            fk.get(freq).remove(key);
            if (fk.get(freq).isEmpty()) {
                fk.remove(freq);
                if (freq == minFreq) minFreq++;
            }
            kf.put(key, freq + 1);
            fk.putIfAbsent(freq + 1, new java.util.LinkedHashSet<>());
            fk.get(freq + 1).add(key);
            return kv.get(key);
        }

        public void put(int key, int value) {
            if (cap == 0) return;
            if (kv.containsKey(key)) {
                kv.put(key, value);
                get(key);
                return;
            }
            if (kv.size() == cap) {
                int evict = fk.get(minFreq).iterator().next();
                fk.get(minFreq).remove(evict);
                kv.remove(evict);
                kf.remove(evict);
            }
            minFreq = 1;
            kv.put(key, value);
            kf.put(key, 1);
            fk.putIfAbsent(1, new java.util.LinkedHashSet<>());
            fk.get(1).add(key);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: LFU Cache");
        System.out.println("=".repeat(60));

        LFUCache c = new LFUCache(2);
        c.put(1, 1);
        c.put(2, 2);
        System.out.println("put(1,1) put(2,2) get(1)=" + c.get(1));
        c.put(3, 3);
        System.out.println("put(3,3) get(2)=" + c.get(2) + " get(3)=" + c.get(3));
    }
}
