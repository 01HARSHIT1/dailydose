/**
 * Basic DSA Problems - LRU Cache
 * Least Recently Used cache: get and put in O(1), evict LRU when at capacity
 */
import java.util.LinkedHashMap;
import java.util.Map;

public class basic_dsa_one_hundred_ninety_four {

    // Problem: capacity. get(key), put(key, value). Evict LRU when full. O(1) get/put.

    public static class LRUCache extends LinkedHashMap<Integer, Integer> {
        private final int capacity;

        public LRUCache(int capacity) {
            super(capacity, 0.75f, true);
            this.capacity = capacity;
        }

        public int get(int key) {
            return super.getOrDefault(key, -1);
        }

        public void put(int key, int value) {
            super.put(key, value);
        }

        @Override
        protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
            return size() > capacity;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: LRU Cache");
        System.out.println("=".repeat(60));

        LRUCache cache = new LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println("get(1) -> " + cache.get(1));
        cache.put(3, 3);
        System.out.println("get(2) -> " + cache.get(2));
        cache.put(4, 4);
        System.out.println("get(1) -> " + cache.get(1));
        System.out.println("get(3) -> " + cache.get(3));
        System.out.println("get(4) -> " + cache.get(4));
    }
}
