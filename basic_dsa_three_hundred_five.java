/**
 * Basic DSA Problems - Search Insert Position
 * Find index or insert position in sorted array
 */
public class basic_dsa_three_hundred_five {

    // Problem: Sorted array nums and target. Return index if found, else insertion position.
    // Insertion position = index where target would be to keep array sorted.

    /**
     * Binary search for lower bound (first >= target).
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

        System.out.println("[1,3,5,6] target=5 -> " + searchInsert(new int[]{1, 3, 5, 6}, 5));
        System.out.println("[1,3,5,6] target=2 -> " + searchInsert(new int[]{1, 3, 5, 6}, 2));
        System.out.println("[1,3,5,6] target=7 -> " + searchInsert(new int[]{1, 3, 5, 6}, 7));
    }
}
