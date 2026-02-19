/**
 * Basic DSA Problems - Water and Jug Problem (LeetCode 365)
 * Can we measure target using two jugs (fill, empty, pour)?
 */
public class basic_dsa_three_hundred_sixty_five {

    // Problem: jug1, jug2 capacity. Measure exactly target? Operations: fill, empty, pour.

    /**
     * Target must be <= jug1+jug2 and divisible by gcd(jug1, jug2).
     * Bézout: ax + by = g. Any multiple of g is achievable.
     * Time O(log(min(a,b)))
     */
    public static boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity > jug1Capacity + jug2Capacity) return false;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Water and Jug Problem");
        System.out.println("=".repeat(60));

        System.out.println("3,5,4 -> " + canMeasureWater(3, 5, 4));
        System.out.println("2,6,5 -> " + canMeasureWater(2, 6, 5));
        System.out.println("1,2,3 -> " + canMeasureWater(1, 2, 3));
    }
}
