/**
 * Basic DSA Problems - Circular Array Loop (LeetCode 457)
 * Detect cycle: same direction, length > 1. Floyd cycle detection.
 */
public class basic_dsa_four_hundred_fifty_seven {

    // Problem: nums circular. Cycle = same sign, len>1, repeats.

    private static int next(int[] nums, int i) {
        int n = nums.length;
        return (i + nums[i] % n + n) % n;
    }

    /**
     * Floyd: slow/fast. Same direction check via nums product > 0.
     * Mark visited as 0. Time O(n), Space O(1)
     */
    public static boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = next(nums, i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(nums, slow)) return true;
                    break;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            int j = i;
            while (nums[j] * nums[next(nums, j)] > 0) {
                nums[j] = 0;
                j = next(nums, j);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Circular Array Loop");
        System.out.println("=".repeat(60));

        System.out.println("[2,-1,1,2,2] -> " + circularArrayLoop(new int[]{2,-1,1,2,2}));
        System.out.println("[-1,2] -> " + circularArrayLoop(new int[]{-1,2}));
        int[] a = {1,-1,5,1,4};
        System.out.println("[1,-1,5,1,4] -> " + circularArrayLoop(a));
    }
}
