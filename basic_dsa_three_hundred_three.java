/**
 * Basic DSA Problems - Binary Search
 * Search for target in sorted array
 */
public class basic_dsa_three_hundred_three {

    // Problem: Sorted array nums, return index of target. Return -1 if not found.

    /**
     * Classic binary search. Halve search space each step.
     * Time O(log n), Space O(1)
     */
    public static int search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Search");
        System.out.println("=".repeat(60));

        System.out.println("[-1,0,3,5,9,12] target=9 -> " + search(new int[]{-1, 0, 3, 5, 9, 12}, 9));
        System.out.println("[-1,0,3,5,9,12] target=2 -> " + search(new int[]{-1, 0, 3, 5, 9, 12}, 2));
        System.out.println("[5] target=5 -> " + search(new int[]{5}, 5));
    }
}
