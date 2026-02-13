/**
 * Basic DSA Problems - House Robber
 * Maximum sum of non-adjacent elements
 */
public class basic_dsa_two_hundred_sixty_seven {

    // Problem: nums[i] = money at house i. Cannot rob two adjacent houses.
    // Return max money you can rob.

    /**
     * DP: rob[i] = max(rob[i-2]+nums[i], rob[i-1]). Use two variables.
     * Time O(n), Space O(1)
     */
    public static int rob(int[] nums) {
        int prev = 0, curr = 0;
        for (int x : nums) {
            int next = Math.max(prev + x, curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: House Robber");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,1] -> " + rob(new int[]{1, 2, 3, 1}));
        System.out.println("[2,7,9,3,1] -> " + rob(new int[]{2, 7, 9, 3, 1}));
    }
}
