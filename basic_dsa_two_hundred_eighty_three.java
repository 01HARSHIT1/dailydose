/**
 * Basic DSA Problems - Summary Ranges
 * Find smallest sorted list of ranges that cover all numbers
 */
public class basic_dsa_two_hundred_eighty_three {

    // Problem: Sorted unique integers. Return smallest sorted list of ranges covering all.
    // [0,1,2,4,5,7] -> ["0->2","4->5","7"]

    /**
     * Scan: extend range while consecutive. Add "a" or "a->b" when gap.
     * Time O(n), Space O(1) excluding output
     */
    public static java.util.List<String> summaryRanges(int[] nums) {
        java.util.List<String> out = new java.util.ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int start = nums[i];
            while (i + 1 < nums.length && nums[i + 1] == nums[i] + 1) i++;
            out.add(start == nums[i] ? String.valueOf(start) : start + "->" + nums[i]);
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Summary Ranges");
        System.out.println("=".repeat(60));

        System.out.println("[0,1,2,4,5,7] -> " + summaryRanges(new int[]{0, 1, 2, 4, 5, 7}));
        System.out.println("[0,2,3,4,6,8,9] -> " + summaryRanges(new int[]{0, 2, 3, 4, 6, 8, 9}));
    }
}
