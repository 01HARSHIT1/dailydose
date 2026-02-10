/**
 * Basic DSA Problems - Koko Eating Bananas
 * Min eating speed so all piles are eaten in h hours (each hour one pile, k bananas per hour from that pile)
 */
public class basic_dsa_one_hundred_eighty_two {

    // Problem: piles[i] = bananas in pile i. In h hours, finish all. k = bananas per hour per pile. Find min k.

    /**
     * Binary search on k. For each k, hours = sum(ceil(pile/k)). If hours <= h, try smaller k.
     * Time O(n log max), Space O(1)
     */
    public static int minEatingSpeed(int[] piles, int h) {
        int lo = 1, hi = 0;
        for (int p : piles) if (p > hi) hi = p;
        while (lo < hi) {
            int k = lo + (hi - lo) / 2;
            long hours = 0;
            for (int p : piles) hours += (p + k - 1) / k;
            if (hours <= h) hi = k;
            else lo = k + 1;
        }
        return lo;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Koko Eating Bananas");
        System.out.println("=".repeat(60));

        System.out.println("[3,6,7,11], h=8 -> " + minEatingSpeed(new int[]{3, 6, 7, 11}, 8));
        System.out.println("[30,11,23,4,20], h=5 -> " + minEatingSpeed(new int[]{30, 11, 23, 4, 20}, 5));
    }
}
