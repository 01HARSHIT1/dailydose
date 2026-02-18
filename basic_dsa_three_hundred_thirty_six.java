/**
 * Basic DSA Problems - Palindrome Pairs (LeetCode 336)
 * Find all pairs (i,j) where words[i] + words[j] is a palindrome
 */
public class basic_dsa_three_hundred_thirty_six {

    // Problem: Array of unique words. Return list of [i,j] where words[i]+words[j] is palindrome.

    private static boolean isPal(String s, int lo, int hi) {
        while (lo < hi) if (s.charAt(lo++) != s.charAt(hi--)) return false;
        return true;
    }

    /**
     * For each word, check all possible splits: prefix+"" and ""+suffix.
     * Use map to find complement. Time O(n*k^2), Space O(n)
     */
    public static java.util.List<java.util.List<Integer>> palindromePairs(String[] words) {
        java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
        java.util.Map<String, Integer> map = new java.util.HashMap<>();
        for (int i = 0; i < words.length; i++) map.put(words[i], i);

        for (int i = 0; i < words.length; i++) {
            String w = words[i];
            for (int j = 0; j <= w.length(); j++) {
                String pre = w.substring(0, j), suf = w.substring(j);
                if (isPal(pre, 0, pre.length() - 1)) {
                    String need = new StringBuilder(suf).reverse().toString();
                    if (map.containsKey(need) && map.get(need) != i)
                        out.add(java.util.Arrays.asList(map.get(need), i));
                }
                if (j < w.length() && isPal(suf, 0, suf.length() - 1)) {
                    String need = new StringBuilder(pre).reverse().toString();
                    if (map.containsKey(need) && map.get(need) != i)
                        out.add(java.util.Arrays.asList(i, map.get(need)));
                }
            }
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Palindrome Pairs");
        System.out.println("=".repeat(60));

        System.out.println("[abcd,dcba,lls,s,sssll] -> " + palindromePairs(new String[]{"abcd","dcba","lls","s","sssll"}));
        System.out.println("[bat,tab,cat] -> " + palindromePairs(new String[]{"bat","tab","cat"}));
        System.out.println("[a,] -> " + palindromePairs(new String[]{"a",""}));
    }
}
