/**
 * Basic DSA Problems - Number of Segments in a String
 * Count the number of segments (words) in a string
 */
public class basic_dsa_one_hundred_forty_seven {

    // Problem: Count the number of segments in string s. A segment is a contiguous sequence
    // of non-space characters. Example: "Hello, my name is John" -> 5

    /**
     * Count segments: increment when we transition from space to non-space
     * Time O(n), Space O(1)
     */
    public static int countSegments(String s) {
        if (s == null || s.isEmpty()) return 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i - 1) == ' ') && s.charAt(i) != ' ') {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Number of Segments in a String");
        System.out.println("=".repeat(60));

        System.out.println("\"Hello, my name is John\" -> " + countSegments("Hello, my name is John"));
        System.out.println("\"\" -> " + countSegments(""));
        System.out.println("\"   \" -> " + countSegments("   "));
        System.out.println("\"a\" -> " + countSegments("a"));
        System.out.println("\"Of all the gin joints in all the towns in all the world\" -> " +
            countSegments("Of all the gin joints in all the towns in all the world"));
    }
}
