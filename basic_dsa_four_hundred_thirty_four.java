/**
 * Basic DSA Problems - Number of Segments in a String (LeetCode 434)
 * Count segments: non-empty substrings separated by spaces
 */
public class basic_dsa_four_hundred_thirty_four {

    // Problem: "Hello, my name is John" -> 5 segments

    /**
     * Count when we enter a segment (non-space after space or at start).
     * Time O(n), Space O(1)
     */
    public static int countSegments(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
            if ((i == 0 || s.charAt(i - 1) == ' ') && s.charAt(i) != ' ')
                cnt++;
        return cnt;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Number of Segments in a String");
        System.out.println("=".repeat(60));

        System.out.println("\"Hello, my name is John\" -> " + countSegments("Hello, my name is John"));
        System.out.println("\"Hello\" -> " + countSegments("Hello"));
        System.out.println("\"   \" -> " + countSegments("   "));
    }
}
