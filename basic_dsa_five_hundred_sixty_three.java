/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_three {

    // Problem 1: Summary Ranges
    // You are given a sorted unique integer array nums.
    // Return the smallest sorted list of ranges that cover all the numbers exactly.
    //
    // Example:
    // nums = [0,1,2,4,5,7] -> ["0->2","4->5","7"]

    /**
     * One pass range expansion
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String[] summaryRanges(int[] nums) {
        if (nums == null) {
            return null;
        }
        if (nums.length == 0) {
            return new String[0];
        }

        java.util.ArrayList<String> ranges = new java.util.ArrayList<>();
        int start = nums[0];
        int prev = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == prev + 1) {
                prev = nums[i];
                continue;
            }

            if (start == prev) {
                ranges.add(String.valueOf(start));
            } else {
                ranges.add(start + "->" + prev);
            }

            start = nums[i];
            prev = nums[i];
        }

        if (start == prev) {
            ranges.add(String.valueOf(start));
        } else {
            ranges.add(start + "->" + prev);
        }

        String[] result = new String[ranges.size()];
        for (int i = 0; i < ranges.size(); i++) {
            result[i] = ranges.get(i);
        }
        return result;
    }

    private static String intArrayToString(int[] arr) {
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

    private static String stringArrayToString(String[] arr) {
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
            sb.append("\"").append(arr[i]).append("\"");
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Summary Ranges");
        System.out.println("=".repeat(60));

        int[] a1 = {0, 1, 2, 4, 5, 7};
        System.out.println("nums = " + intArrayToString(a1) + " -> " + stringArrayToString(summaryRanges(a1)));

        int[] a2 = {0, 2, 3, 4, 6, 8, 9};
        System.out.println("nums = " + intArrayToString(a2) + " -> " + stringArrayToString(summaryRanges(a2)));

        int[] a3 = {1};
        System.out.println("nums = " + intArrayToString(a3) + " -> " + stringArrayToString(summaryRanges(a3)));

        int[] a4 = {};
        System.out.println("nums = " + intArrayToString(a4) + " -> " + stringArrayToString(summaryRanges(a4)));

        System.out.println("nums = null -> " + stringArrayToString(summaryRanges(null)));
    }
}
