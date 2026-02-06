/**
 * Basic DSA Problems - Binary Search
 * Find target in a sorted array using binary search
 */
public class basic_dsa_one_hundred_one {

    // Problem: Given a sorted integer array nums and target, return the index of target.
    // If target is not present, return -1.

    /**
     * Classic binary search: narrow range by comparing mid with target.
     * Time O(log n), Space O(1)
     */
    public static int binarySearch(int[] nums, int target) {
        if (nums == null) return -1;
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Search");
        System.out.println("=".repeat(60));

        int[] a = { -1, 0, 3, 5, 9, 12 };
        System.out.println("nums = [-1,0,3,5,9,12], target = 9 -> " + binarySearch(a, 9));
        System.out.println("nums = [-1,0,3,5,9,12], target = 2 -> " + binarySearch(a, 2));

        int[] b = { 5 };
        System.out.println("nums = [5], target = 5 -> " + binarySearch(b, 5));
        System.out.println("nums = [5], target = -5 -> " + binarySearch(b, -5));
    }
}
