/**
 * Basic DSA Problems - Roman to Integer
 * Convert Roman numeral string to integer
 */
import java.util.HashMap;
import java.util.Map;

public class basic_dsa_two_hundred_nineteen {

    // Problem: Valid Roman numeral string. Return integer value.

    /**
     * If next symbol value > current, subtract current (e.g. IV = -1 + 5). Else add current.
     * Time O(n), Space O(1)
     */
    public static int romanToInt(String s) {
        Map<Character, Integer> map = Map.of(
            'I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000
        );
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int v = map.get(s.charAt(i));
            if (i + 1 < s.length() && map.get(s.charAt(i + 1)) > v) sum -= v;
            else sum += v;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Roman to Integer");
        System.out.println("=".repeat(60));

        System.out.println("III -> " + romanToInt("III"));
        System.out.println("LVIII -> " + romanToInt("LVIII"));
        System.out.println("MCMXCIV -> " + romanToInt("MCMXCIV"));
    }
}
