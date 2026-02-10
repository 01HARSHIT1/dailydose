/**
 * Basic DSA Problems - Encode and Decode Strings (Design)
 * Encode list of strings to single string; decode back to list (length prefix)
 */
import java.util.ArrayList;
import java.util.List;

public class basic_dsa_two_hundred_three {

    // Problem: Encode list of strings to one string; decode back. Strings can contain any char.

    /**
     * Encode: for each string write length (e.g. 4 chars) then the string. Decode: read length, read that many chars.
     */
    public static String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s.length()).append('#').append(s);
        }
        return sb.toString();
    }

    public static List<String> decode(String s) {
        List<String> out = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            int j = s.indexOf('#', i);
            int len = Integer.parseInt(s.substring(i, j));
            out.add(s.substring(j + 1, j + 1 + len));
            i = j + 1 + len;
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Encode and Decode Strings");
        System.out.println("=".repeat(60));

        List<String> list = List.of("Hello", "World", "!");
        String enc = encode(list);
        System.out.println("Encoded -> " + enc);
        System.out.println("Decoded -> " + decode(enc));
    }
}
