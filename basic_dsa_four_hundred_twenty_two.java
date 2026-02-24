/**
 * Basic DSA Problems - Valid Word Square (LeetCode 422)
 * Check if kth row and kth column read the same string for all k
 */
public class basic_dsa_four_hundred_twenty_two {

    // Problem: words array. For each k, row k == column k.

    /**
     * For each k: build row = words[k], col = words[i].charAt(k) for valid i.
     * Time O(n * m), Space O(m)
     */
    public static boolean validWordSquare(java.util.List<String> words) {
        int n = words.size();
        for (int k = 0; k < n; k++) {
            String row = words.get(k);
            StringBuilder col = new StringBuilder();
            for (int i = 0; i < n; i++)
                if (k < words.get(i).length()) col.append(words.get(i).charAt(k));
            if (!row.equals(col.toString())) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Word Square");
        System.out.println("=".repeat(60));

        java.util.List<String> w1 = java.util.Arrays.asList("abcd","bnrt","crmy","dtye");
        System.out.println("[\"abcd\",\"bnrt\",\"crmy\",\"dtye\"] -> " + validWordSquare(w1));

        java.util.List<String> w2 = java.util.Arrays.asList("abcd","bnrt","crm","dt");
        System.out.println("[\"abcd\",\"bnrt\",\"crm\",\"dt\"] -> " + validWordSquare(w2));

        java.util.List<String> w3 = java.util.Arrays.asList("ball","area","read","lady");
        System.out.println("[\"ball\",\"area\",\"read\",\"lady\"] -> " + validWordSquare(w3));
    }
}
