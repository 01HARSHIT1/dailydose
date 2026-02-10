/**
 * Basic DSA Problems - Can Place Flowers
 * Place n flowers in flowerbed (adjacent = no flowers allowed)
 */
public class basic_dsa_two_hundred_eleven {

    // Problem: flowerbed[i]=1 means planted, 0 empty. Cannot plant adjacent. Return true if n new flowers can be placed.

    /**
     * Greedy: plant at each 0 where left and right are 0 (or boundary). Count and compare with n.
     * Time O(L), Space O(1)
     */
    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.length && count < n; i++) {
            if (flowerbed[i] == 1) continue;
            boolean leftOk = (i == 0 || flowerbed[i - 1] == 0);
            boolean rightOk = (i == flowerbed.length - 1 || flowerbed[i + 1] == 0);
            if (leftOk && rightOk) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Can Place Flowers");
        System.out.println("=".repeat(60));

        System.out.println("[1,0,0,0,1], n=1 -> " + canPlaceFlowers(new int[]{1, 0, 0, 0, 1}, 1));
        System.out.println("[1,0,0,0,1], n=2 -> " + canPlaceFlowers(new int[]{1, 0, 0, 0, 1}, 2));
    }
}
