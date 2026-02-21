/**
 * Basic DSA Problems - Rotate Function (LeetCode 396)
 * Max F(k) = sum(i * arr[i]) over rotations
 */
public class basic_dsa_three_hundred_ninety_six {

    // Problem: F(k) = sum i*arr[i] for rotated array. Return max F(k).

    /**
     * F(k+1) - F(k) = sum(arr) - n*arr[n-1-k]. Compute F(0), then iterate.
     * Time O(n), Space O(1)
     */
    public static int maxRotateFunction(int[] nums) {
        int n = nums.length;
        long sum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        long max = f;
        for (int k = 1; k < n; k++) {
            f += sum - n * nums[n - k];
            max = Math.max(max, f);
        }
        return (int) max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Rotate Function");
        System.out.println("=".repeat(60));

        System.out.println("[4,3,2,6] -> " + maxRotateFunction(new int[]{4, 3, 2, 6}));
        System.out.println("[100] -> " + maxRotateFunction(new int[]{100}));
    }
}
