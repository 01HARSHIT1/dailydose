/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_eight {

    // Problem 1: Max Consecutive Ones
    // Given a binary array nums, return the maximum number of consecutive 1's.
    //
    // Example:
    // nums = [1,1,0,1,1,1] -> 3

    /**
     * Single pass streak counter
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer findMaxConsecutiveOnes(int[] nums) {
        if (nums == null) {
            return null;
        }

        int best = 0;
        int streak = 0;
        for (int x : nums) {
            if (x == 1) {
                streak++;
                if (streak > best) {
                    best = streak;
                }
            } else {
                streak = 0;
            }
        }
        return best;
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Max Consecutive Ones");
        System.out.println("=".repeat(60));

        int[] a = {1, 1, 0, 1, 1, 1};
        System.out.println("nums = " + arrayToString(a) + " -> " + findMaxConsecutiveOnes(a));

        int[] b = {1, 0, 1, 1, 0, 1};
        System.out.println("nums = " + arrayToString(b) + " -> " + findMaxConsecutiveOnes(b));

        int[] c = {0, 0, 0};
        System.out.println("nums = " + arrayToString(c) + " -> " + findMaxConsecutiveOnes(c));

        int[] d = {};
        System.out.println("nums = " + arrayToString(d) + " -> " + findMaxConsecutiveOnes(d));

        System.out.println("nums = null -> " + findMaxConsecutiveOnes(null));
    }
}
