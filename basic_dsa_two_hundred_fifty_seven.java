/**
 * Basic DSA Problems - Longest Uncommon Subsequence I
 * Find longest uncommon subsequence of two strings
 */
public class basic_dsa_two_hundred_fifty_seven {

    // Problem: Uncommon subsequence of a w.r.t b: subseq of a that is NOT a subseq of b.
    // Return length of longest uncommon subseq, or -1 if none.

    /**
     * If a.equals(b) -> -1. Else longest uncommon subseq is a itself (if a not subseq of b),
     * or b itself (if b not subseq of a). So answer is max(len(a), len(b)).
     * Time O(n), Space O(1)
     */
    public static int findLUSlength(String a, String b) {
        if (a.equals(b)) return -1;
        return Math.max(a.length(), b.length());
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Uncommon Subsequence I");
        System.out.println("=".repeat(60));

        System.out.println("aba, cdc -> " + findLUSlength("aba", "cdc"));
        System.out.println("aaa, aaa -> " + findLUSlength("aaa", "aaa"));
        System.out.println("aaa, aaa -> " + findLUSlength("aaa", "bbb"));
    }
}
