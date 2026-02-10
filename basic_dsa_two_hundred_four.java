/**
 * Basic DSA Problems - Longest Consecutive Sequence
 * Length of longest consecutive elements sequence (unsorted array, O(n) expected)
 */
import java.util.HashSet;
import java.util.Set;

public class basic_dsa_two_hundred_four {

    // Problem: Unsorted array. Return length of longest consecutive sequence (e.g. 1,2,3,4).

    /**
     * Put all in set. For each x, if x-1 not in set, count streak (x, x+1, ...). Track max.
     * Time O(n), Space O(n)
     */
    public static int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) set.add(x);
        int max = 0;
        for (int x : set) {
            if (!set.contains(x - 1)) {
                int len = 0;
                while (set.contains(x + len)) len++;
                max = Math.max(max, len);
            }
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Consecutive Sequence");
        System.out.println("=".repeat(60));

        System.out.println("[100,4,200,1,3,2] -> " + longestConsecutive(new int[]{100, 4, 200, 1, 3, 2}));
        System.out.println("[0,3,7,2,5,8,4,6,0,1] -> " + longestConsecutive(new int[]{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}));
    }
}
