/**
 * Basic DSA Problems - Nim Game
 * Optimal play in Nim with n stones
 */
public class basic_dsa_two_hundred_fifty_nine {

    // Problem: n stones. You and opponent take 1-3 stones per turn. You start.
    // Return true if you can win with optimal play.

    /**
     * Losing positions: n divisible by 4. You can always make n%4==0 for opponent.
     * Time O(1), Space O(1)
     */
    public static boolean canWinNim(int n) {
        return n % 4 != 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Nim Game");
        System.out.println("=".repeat(60));

        System.out.println("4 -> " + canWinNim(4));
        System.out.println("1 -> " + canWinNim(1));
        System.out.println("2 -> " + canWinNim(2));
        System.out.println("5 -> " + canWinNim(5));
    }
}
