/**
 * Basic DSA Problems - Time Based Key-Value Store
 * Store key-value pairs with timestamps; get value for key at largest timestamp <= given time
 */
import java.util.*;

public class basic_dsa_one_hundred_eighty_five {

    // Problem: set(key, value, timestamp); get(key, timestamp) returns value at largest time <= timestamp.

    public static class TimeMap {
        Map<String, TreeMap<Integer, String>> store = new HashMap<>();

        public void set(String key, String value, int timestamp) {
            store.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp, value);
        }

        public String get(String key, int timestamp) {
            if (!store.containsKey(key)) return "";
            TreeMap<Integer, String> tm = store.get(key);
            Integer floor = tm.floorKey(timestamp);
            return floor == null ? "" : tm.get(floor);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Time Based Key-Value Store");
        System.out.println("=".repeat(60));

        TimeMap tm = new TimeMap();
        tm.set("foo", "bar", 1);
        System.out.println("get(foo, 1) -> " + tm.get("foo", 1));
        System.out.println("get(foo, 3) -> " + tm.get("foo", 3));
        tm.set("foo", "bar2", 4);
        System.out.println("get(foo, 4) -> " + tm.get("foo", 4));
        System.out.println("get(foo, 5) -> " + tm.get("foo", 5));
    }
}
