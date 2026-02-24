/**
 * Basic DSA Problems - Maximum XOR of Two Numbers in an Array (LeetCode 421)
 * Find max XOR of any two numbers
 */
public class basic_dsa_four_hundred_twenty_one {

    // Problem: nums array. Find max (nums[i] ^ nums[j]).

    /**
     * Greedy bit-by-bit: for each bit try setting it, check if two prefixes XOR to candidate.
     * Time O(n * 32), Space O(n)
     */
    public static int findMaximumXOR(int[] nums) {
        int maxNum = 0;
        for (int x : nums) if (x > maxNum) maxNum = x;
        if (maxNum == 0) return 0;
        int maxBit = (int) (Math.log(maxNum) / Math.log(2));
        int ans = 0, prefixMask = 0;
        for (int i = maxBit; i >= 0; i--) {
            prefixMask |= 1 << i;
            java.util.Set<Integer> prefixes = new java.util.HashSet<>();
            for (int num : nums) prefixes.add(num & prefixMask);
            int candidate = ans | (1 << i);
            for (int p : prefixes)
                if (prefixes.contains(p ^ candidate)) { ans = candidate; break; }
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Maximum XOR of Two Numbers in an Array");
        System.out.println("=".repeat(60));

        System.out.println("[3,10,5,25,2,8] -> " + findMaximumXOR(new int[]{3,10,5,25,2,8}));
        System.out.println("[14,70,53,83,49,91,36,80,92,51,66,70] -> " + findMaximumXOR(new int[]{14,70,53,83,49,91,36,80,92,51,66,70}));
    }
}
