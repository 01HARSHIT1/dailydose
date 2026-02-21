/**
 * Basic DSA Problems - UTF-8 Validation (LeetCode 393)
 * Check if data array is valid UTF-8 encoding
 */
public class basic_dsa_three_hundred_ninety_three {

    // Problem: data[i] is byte (lower 8 bits). Validate UTF-8 sequence.

    /**
     * Count leading 1s for start byte; expect that many 10xxxxxx continuation bytes.
     * Time O(n), Space O(1)
     */
    public static boolean validUtf8(int[] data) {
        int i = 0;
        while (i < data.length) {
            int d = data[i] & 0xFF;
            int n = 0;
            if ((d & 0x80) == 0) n = 1;
            else if ((d & 0xE0) == 0xC0) n = 2;
            else if ((d & 0xF0) == 0xE0) n = 3;
            else if ((d & 0xF8) == 0xF0) n = 4;
            else return false;
            if (i + n > data.length) return false;
            for (int j = 1; j < n; j++)
                if ((data[i + j] & 0xC0) != 0x80) return false;
            i += n;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: UTF-8 Validation");
        System.out.println("=".repeat(60));

        System.out.println("[197,130,1] -> " + validUtf8(new int[]{197, 130, 1}));
        System.out.println("[235,140,4] -> " + validUtf8(new int[]{235, 140, 4}));
    }
}
