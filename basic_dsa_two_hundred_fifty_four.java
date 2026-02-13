/**
 * Basic DSA Problems - Hamming Distance
 * Count positions where two integers differ in binary
 */
public class basic_dsa_two_hundred_fifty_four {

    // Problem: Given integers x and y, return Hamming distance (number of differing bits).

    /**
     * XOR gives 1 where bits differ. Count set bits in x ^ y.
     * Time O(1), Space O(1)
     */
    public static int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n >>>= 1;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Hamming Distance");
        System.out.println("=".repeat(60));

        System.out.println("1, 4 -> " + hammingDistance(1, 4));
        System.out.println("3, 1 -> " + hammingDistance(3, 1));
    }
}
