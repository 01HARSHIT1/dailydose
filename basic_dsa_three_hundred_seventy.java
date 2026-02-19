/**
 * Basic DSA Problems - Range Addition (LeetCode 370)
 * Apply range updates [start,end,inc] to zero array, return final result
 */
public class basic_dsa_three_hundred_seventy {

    // Problem: length, updates[i]=[start,end,inc]. Add inc to arr[start..end]. Return arr.

    /**
     * Difference array: diff[start]+=inc, diff[end+1]-=inc. Prefix sum = result.
     * Time O(n + k), Space O(n)
     */
    public static int[] getModifiedArray(int length, int[][] updates) {
        int[] diff = new int[length + 1];
        for (int[] u : updates) {
            diff[u[0]] += u[2];
            if (u[1] + 1 < length + 1) diff[u[1] + 1] -= u[2];
        }
        int[] out = new int[length];
        int cur = 0;
        for (int i = 0; i < length; i++) {
            cur += diff[i];
            out[i] = cur;
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Range Addition");
        System.out.println("=".repeat(60));

        System.out.println("length=5, [[1,3,2],[2,4,3],[0,2,-2]] -> "
                + java.util.Arrays.toString(getModifiedArray(5, new int[][]{{1,3,2},{2,4,3},{0,2,-2}})));
    }
}
