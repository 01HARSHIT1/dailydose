/**
 * Basic DSA Problems - Minimum Moves to Equal Array Elements
 * Find minimum increments to make all elements equal
 */
public class basic_dsa_two_hundred_forty_seven {

    // Problem: Increment n-1 elements by 1 each move. Return min moves to make all equal.
    // Math: incrementing n-1 is same as decrementing 1. So min moves = sum(nums) - n * min.

    /**
     * Each move effectively decrements one element by 1. All must reach min. So moves = sum - n*min.
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

        System.out.println("[1,2,3] -> " + minMoves(new int[]{1, 2, 3}));
        System.out.println("[1,1,1] -> " + minMoves(new int[]{1, 1, 1}));
    }
}
