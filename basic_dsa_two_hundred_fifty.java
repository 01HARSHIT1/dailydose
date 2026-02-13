/**
 * Basic DSA Problems - Heaters
 * Find minimum radius so all houses can be warmed by heaters
 */
public class basic_dsa_two_hundred_fifty {

    // Problem: houses[] and heaters[] positions. Each heater warms radius r.
    // Return minimum r so every house is within r of at least one heater.

    /**
     * Sort both. For each house, binary search nearest heater. Take max distance.
     * Time O(n log n + m log m), Space O(1)
     */
    public static int findRadius(int[] houses, int[] heaters) {
        java.util.Arrays.sort(houses);
        java.util.Arrays.sort(heaters);
        int maxDist = 0;
        for (int h : houses) {
            int idx = java.util.Arrays.binarySearch(heaters, h);
            if (idx >= 0) continue;
            idx = -(idx + 1);
            int d = Integer.MAX_VALUE;
            if (idx < heaters.length) d = heaters[idx] - h;
            if (idx > 0) d = Math.min(d, h - heaters[idx - 1]);
            maxDist = Math.max(maxDist, d);
        }
        return maxDist;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Heaters");
        System.out.println("=".repeat(60));

        System.out.println("houses=[1,2,3], heaters=[2] -> " + findRadius(new int[]{1, 2, 3}, new int[]{2}));
        System.out.println("houses=[1,2,3,4], heaters=[1,4] -> " + findRadius(new int[]{1, 2, 3, 4}, new int[]{1, 4}));
    }
}
