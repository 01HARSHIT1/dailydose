/**
 * Basic DSA Problems - Shuffle an Array (LeetCode 384)
 * reset() returns original, shuffle() returns random permutation (Fisher-Yates)
 */
public class basic_dsa_three_hundred_eighty_four {

    // Problem: reset() -> original, shuffle() -> random permutation.

    static class Solution {
        int[] orig;
        int[] arr;
        java.util.Random rnd = new java.util.Random();

        Solution(int[] nums) {
            orig = nums.clone();
            arr = nums.clone();
        }

        public int[] reset() {
            arr = orig.clone();
            return arr;
        }

        public int[] shuffle() {
            for (int i = arr.length - 1; i > 0; i--) {
                int j = rnd.nextInt(i + 1);
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
            return arr;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Shuffle an Array");
        System.out.println("=".repeat(60));

        Solution sol = new Solution(new int[]{1, 2, 3});
        System.out.println("init [1,2,3], shuffle -> " + java.util.Arrays.toString(sol.shuffle()));
        System.out.println("reset -> " + java.util.Arrays.toString(sol.reset()));
    }
}
