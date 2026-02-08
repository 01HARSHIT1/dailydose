/**
 * Basic DSA Problems - Range Sum Query (Immutable)
 * Sum of elements between indices left and right
 */
public class basic_dsa_one_hundred_forty_one {

    // Problem: Given integer array nums, support sumRange(left, right) = sum of elements from index left to right inclusive.
    // Use prefix sum for O(1) sumRange after O(n) preprocessing.

    private final int[] prefix;

    public basic_dsa_one_hundred_forty_one(int[] nums) {
        prefix = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    public int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Range Sum Query - Immutable");
        System.out.println("=".repeat(60));

        int[] nums = { -2, 0, 3, -5, 2, -1 };
        basic_dsa_one_hundred_forty_one obj = new basic_dsa_one_hundred_forty_one(nums);

        System.out.println("sumRange(0, 2) -> " + obj.sumRange(0, 2));   // 1
        System.out.println("sumRange(2, 5) -> " + obj.sumRange(2, 5));   // -1
        System.out.println("sumRange(0, 5) -> " + obj.sumRange(0, 5));   // -3
    }
}
