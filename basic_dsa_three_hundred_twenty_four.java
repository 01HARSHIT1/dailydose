/**
 * Basic DSA Problems - 3Sum
 * Find all unique triplets that sum to zero
 */
public class basic_dsa_three_hundred_twenty_four {

    // Problem: Array nums. Return all unique triplets [a,b,c] where a+b+c=0.

    /**
     * Sort, fix first element, two-pointer for remaining two. Skip duplicates.
     * Time O(n^2), Space O(1) excluding output
     */
    public static java.util.List<java.util.List<Integer>> threeSum(int[] nums) {
        java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
        java.util.Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1, hi = nums.length - 1, target = -nums[i];
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum == target) {
                    out.add(java.util.Arrays.asList(nums[i], nums[lo], nums[hi]));
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++;
                    hi--;
                } else if (sum < target) lo++;
                else hi--;
            }
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: 3Sum");
        System.out.println("=".repeat(60));

        System.out.println("[-1,0,1,2,-1,-4] -> " + threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
        System.out.println("[0,0,0] -> " + threeSum(new int[]{0, 0, 0}));
    }
}
