/**
 * Basic DSA Problems - Search Insert Position
 * Find index to insert target in sorted array
 */
public class basic_dsa_three_hundred_thirteen {

    // Problem: Sorted distinct array and target. Return index where target would be inserted.

    /**
     * Binary search: find lower bound (first >= target).
     * Time O(log n), Space O(1)
     */
    public static int searchInsert(int[] nums, int target) {
        int lo = 0, hi = nums.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Search Insert Position");
        System.out.println("=".repeat(60));

        System.out.println("[1,3,5,6], 5 -> " + searchInsert(new int[]{1, 3, 5, 6}, 5));
        System.out.println("[1,3,5,6], 2 -> " + searchInsert(new int[]{1, 3, 5, 6}, 2));
        System.out.println("[1,3,5,6], 7 -> " + searchInsert(new int[]{1, 3, 5, 6}, 7));
    }
}
