/**
 * Basic DSA Problems - Decode String (LeetCode 394)
 * k[encoded_string] -> repeat encoded_string k times
 */
public class basic_dsa_three_hundred_ninety_four {

    // Problem: "3[a]2[bc]" -> "aaabcbc", "3[a2[c]]" -> "accaccacc".

    /**
     * Recursive/stack: parse number, then "[...]" and repeat.
     * Time O(maxK * n), Space O(n)
     */
    public static String decodeString(String s) {
        int[] i = {0};
        return parse(s, i);
    }

    private static String parse(String s, int[] i) {
        StringBuilder sb = new StringBuilder();
        while (i[0] < s.length() && s.charAt(i[0]) != ']') {
            if (Character.isLetter(s.charAt(i[0])))
                sb.append(s.charAt(i[0]++));
            else if (Character.isDigit(s.charAt(i[0]))) {
                int k = 0;
                while (i[0] < s.length() && Character.isDigit(s.charAt(i[0])))
                    k = k * 10 + (s.charAt(i[0]++) - '0');
                i[0]++;
                String inner = parse(s, i);
                i[0]++;
                for (int j = 0; j < k; j++) sb.append(inner);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Decode String");
        System.out.println("=".repeat(60));

        System.out.println("3[a]2[bc] -> " + decodeString("3[a]2[bc]"));
        System.out.println("3[a2[c]] -> " + decodeString("3[a2[c]]"));
    }
}
