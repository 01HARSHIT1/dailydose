/**
 * Basic DSA Problems - Sort Transformed Array (LeetCode 360)
 * Apply f(x)=ax^2+bx+c to sorted nums, return sorted result
 */
public class basic_dsa_three_hundred_sixty {

    // Problem: Sorted nums, a,b,c. Return sorted array of f(x)=a*x*x+b*x+c for each x.

    /**
     * Parabola: a>0 opens up (min at vertex), a<0 opens down (max at vertex).
     * Two-pointer from ends, fill result from correct end based on a.
     * Time O(n), Space O(n)
     */
    public static int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] out = new int[n];
        int i = 0, j = n - 1;
        int idx = a >= 0 ? n - 1 : 0;
        int step = a >= 0 ? -1 : 1;

        while (i <= j) {
            int fi = f(nums[i], a, b, c);
            int fj = f(nums[j], a, b, c);
            if (a >= 0) {
                out[idx] = Math.max(fi, fj);
                if (fi >= fj) i++; else j--;
            } else {
                out[idx] = Math.min(fi, fj);
                if (fi <= fj) i++; else j--;
            }
            idx += step;
        }
        return out;
    }

    private static int f(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sort Transformed Array");
        System.out.println("=".repeat(60));

        System.out.println("[-4,-2,2,4], a=1,b=3,c=5 -> " + java.util.Arrays.toString(sortTransformedArray(new int[]{-4,-2,2,4}, 1, 3, 5)));
        System.out.println("[-4,-2,2,4], a=-1,b=3,c=5 -> " + java.util.Arrays.toString(sortTransformedArray(new int[]{-4,-2,2,4}, -1, 3, 5)));
    }
}
