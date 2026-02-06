/**
 * Basic DSA Problems - Search Insert Position
 * Find index where target would be inserted in sorted array
 */
public class basic_dsa_one_hundred_four {

    // Problem: Given a sorted distinct integer array and target, return the index if target is found.
    // If not, return the index where it would be inserted to keep the array sorted.

    /**
     * Binary search: find first position where nums[mid] >= target; that is insert position.
     * Time O(log n), Space O(1)
     */
    public static int searchInsert(int[] nums, int target) {
        if (nums == null) return 0;
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Search Insert Position");
        System.out.println("=".repeat(60));

        int[] a = { 1, 3, 5, 6 };
        System.out.println("[1,3,5,6], target = 5 -> " + searchInsert(a, 5));
        System.out.println("[1,3,5,6], target = 2 -> " + searchInsert(a, 2));
        System.out.println("[1,3,5,6], target = 7 -> " + searchInsert(a, 7));

        int[] b = { 1, 3, 5, 6 };
        System.out.println("[1,3,5,6], target = 0 -> " + searchInsert(b, 0));
    }
}
