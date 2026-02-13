/**
 * Basic DSA Problems - Count Segments
 * Count the number of segments in a string
 */
public class basic_dsa_two_hundred_forty_four {

    // Problem: A segment is a contiguous sequence of non-space characters.
    // Return the number of segments in s.

    /**
     * Count transitions: segment starts when (prev was space or start) and current is non-space.
     * Time O(n), Space O(1)
     */
    public static int countSegments(String s) {
        int count = 0;
        boolean inSegment = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ' ') {
                if (!inSegment) {
                    count++;
                    inSegment = true;
                }
            } else {
                inSegment = false;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Count Segments");
        System.out.println("=".repeat(60));

        System.out.println("\"Hello, my name is John\" -> " + countSegments("Hello, my name is John"));
        System.out.println("\"Hello\" -> " + countSegments("Hello"));
        System.out.println("\"\" -> " + countSegments(""));
        System.out.println("\"                \" -> " + countSegments("                "));
    }
}
