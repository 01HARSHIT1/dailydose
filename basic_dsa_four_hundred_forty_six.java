/**
 * Basic DSA Problems - Arithmetic Slices II - Subsequence (LeetCode 446)
 * Count arithmetic subsequences with at least 3 elements (constant diff)
 */
public class basic_dsa_four_hundred_forty_six {

    // Problem: subsequences with >=3 elements, same diff between consecutive.

    /**
     * DP: f[i][d] = count of subsequences (len>=2) ending at i with diff d.
     * ans += f[j][d], f[i][d] += f[j][d]+1 for each j<i.
     * Time O(n^2), Space O(n^2)
     */
    public static int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        java.util.Map<Long, Integer>[] f = new java.util.Map[n];
        for (int i = 0; i < n; i++) f[i] = new java.util.HashMap<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long) nums[i] - nums[j];
                int cnt = f[j].getOrDefault(d, 0);
                ans += cnt;
                f[i].merge(d, cnt + 1, Integer::sum);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Arithmetic Slices II - Subsequence");
        System.out.println("=".repeat(60));

        System.out.println("[2,4,6,8,10] -> " + numberOfArithmeticSlices(new int[]{2,4,6,8,10}));
        System.out.println("[7,7,7,7,7] -> " + numberOfArithmeticSlices(new int[]{7,7,7,7,7}));
    }
}
