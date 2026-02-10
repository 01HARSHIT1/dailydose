/**
 * Basic DSA Problems - 3Sum
 * Find all unique triplets that add up to zero
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class basic_dsa_one_hundred_ninety_eight {

    // Problem: Array nums. Return all unique triplets (a,b,c) such that a+b+c=0.

    /**
     * Sort, fix one element, two-pointer for the other two. Skip duplicates.
     * Time O(n^2), Space O(1) excluding output
     */
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> out = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == 0) {
                    out.add(Arrays.asList(nums[i], nums[lo], nums[hi]));
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++;
                    hi--;
                } else if (sum < 0) lo++;
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
