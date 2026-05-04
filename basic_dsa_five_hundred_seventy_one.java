/**
 * Basic DSA Problems - One Fundamental Two Pointers Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_one {

    // Problem 1: Squares of a Sorted Array
    // Given an integer array nums sorted in non-decreasing order,
    // return an array of the squares of each number sorted in non-decreasing order.
    //
    // Example:
    // nums = [-4,-1,0,3,10] -> [0,1,9,16,100]

    /**
     * Fill output from end using two pointers
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] sortedSquares(int[] nums) {
        if (nums == null) {
            return null;
        }

        int n = nums.length;
        int[] result = new int[n];
        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            if (leftSq > rightSq) {
                result[pos--] = leftSq;
                left++;
            } else {
                result[pos--] = rightSq;
                right--;
            }
        }

        return result;
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
        System.out.println("Problem 1: Squares of a Sorted Array");
        System.out.println("=".repeat(60));

        int[] a1 = {-4, -1, 0, 3, 10};
        System.out.println("nums = " + arrayToString(a1) + " -> " + arrayToString(sortedSquares(a1)));

        int[] a2 = {-7, -3, 2, 3, 11};
        System.out.println("nums = " + arrayToString(a2) + " -> " + arrayToString(sortedSquares(a2)));

        int[] a3 = {0};
        System.out.println("nums = " + arrayToString(a3) + " -> " + arrayToString(sortedSquares(a3)));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + " -> " + arrayToString(sortedSquares(a4)));

        System.out.println("nums = null -> " + arrayToString(sortedSquares(null)));
    }
}
