/**
 * Basic DSA Problems - Gray Code
 * Generate n-bit Gray code sequence
 */
import java.util.*;

public class basic_dsa_one_hundred_thirty_nine {

    // Problem: Generate n-bit Gray code sequence. Gray code: successive values differ by exactly one bit.
    // Example: n=2 -> [0,1,3,2] (00,01,11,10)

    /**
     * Gray code: i-th value = i ^ (i >> 1)
     * Time O(2^n), Space O(2^n)
     */
    public static List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        int size = 1 << n;   // 2^n

        for (int i = 0; i < size; i++) {
            result.add(i ^ (i >> 1));
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Gray Code");
        System.out.println("=".repeat(60));

        System.out.println("n=2 -> " + grayCode(2));
        System.out.println("n=1 -> " + grayCode(1));
        System.out.println("n=3 -> " + grayCode(3));
    }
}
