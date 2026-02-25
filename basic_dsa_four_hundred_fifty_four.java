/**
 * Basic DSA Problems - 4Sum II (LeetCode 454)
 * Count tuples (i,j,k,l) where A[i]+B[j]+C[k]+D[l]=0
 */
public class basic_dsa_four_hundred_fifty_four {

    // Problem: Four arrays. Count a+b+c+d=0.

    /**
     * Map a+b -> count. For each c+d, add count of -(c+d).
     * Time O(n^2), Space O(n^2)
     */
    public static int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        java.util.Map<Integer, Integer> cnt = new java.util.HashMap<>();
        for (int a : nums1)
            for (int b : nums2) cnt.put(a + b, cnt.getOrDefault(a + b, 0) + 1);
        int ans = 0;
        for (int c : nums3)
            for (int d : nums4) ans += cnt.getOrDefault(-(c + d), 0);
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: 4Sum II");
        System.out.println("=".repeat(60));

        System.out.println("A=[1,2] B=[-2,-1] C=[-1,2] D=[0,2] -> " + fourSumCount(new int[]{1,2}, new int[]{-2,-1}, new int[]{-1,2}, new int[]{0,2}));
        System.out.println("A=[0] B=[0] C=[0] D=[0] -> " + fourSumCount(new int[]{0}, new int[]{0}, new int[]{0}, new int[]{0}));
    }
}
