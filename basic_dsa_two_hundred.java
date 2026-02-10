/**
 * Basic DSA Problems - Group Anagrams
 * Group strings that are anagrams of each other
 */
import java.util.*;


public class basic_dsa_two_hundred {

    // Problem: Array of strings. Group those that are anagrams. Return list of groups.

    /**
     * Key = sorted string (or count signature). Map key -> list of strings.
     * Time O(n * k log k) for k = max string length, Space O(n * k)
     */
    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] a = s.toCharArray();
            Arrays.sort(a);
            String key = new String(a);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(map.values());
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Group Anagrams");
        System.out.println("=".repeat(60));

        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        System.out.println("Groups -> " + groupAnagrams(strs));
    }
}
