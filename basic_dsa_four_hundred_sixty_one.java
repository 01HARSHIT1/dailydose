/**
 * Basic DSA Problems - Hamming Distance (LeetCode 461)
 * Number of positions where bits differ in x and y
 */
public class basic_dsa_four_hundred_sixty_one {

    // Problem: hamming distance = count of differing bits.

    /**
     * XOR gives differing bits. Count set bits (n & (n-1) trick).
     * Time O(1), Space O(1)
     */
    public static int hammingDistance(int x, int y) {
        int z = x ^ y, cnt = 0;
        while (z != 0) {
            z &= z - 1;
            cnt++;
        }
        return cnt;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Hamming Distance");
        System.out.println("=".repeat(60));

        System.out.println("1, 4 -> " + hammingDistance(1, 4));
        System.out.println("3, 1 -> " + hammingDistance(3, 1));
    }
}
