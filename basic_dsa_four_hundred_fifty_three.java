/**
 * Basic DSA Problems - Minimum Moves to Equal Array Elements (LeetCode 453)
 * Each move: increment n-1 elements by 1. Min moves to make all equal.
 */
public class basic_dsa_four_hundred_fifty_three {

    // Problem: [1,2,3] -> 3 moves. Increment n-1 = decrement 1.

    /**
     * Equivalent to decrementing 1 element per move. Ans = sum - min*n.
     * Time O(n), Space O(1)
     */
    public static int minMoves(int[] nums) {
        int min = nums[0], sum = 0;
        for (int x : nums) {
            if (x < min) min = x;
            sum += x;
        }
        return sum - min * nums.length;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Minimum Moves to Equal Array Elements");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3] -> " + minMoves(new int[]{1,2,3}));
        System.out.println("[1,1,1] -> " + minMoves(new int[]{1,1,1}));
        System.out.println("[1,2,3,4] -> " + minMoves(new int[]{1,2,3,4}));
    }
}
