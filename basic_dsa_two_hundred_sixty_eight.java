/**
 * Basic DSA Problems - Best Time to Buy and Sell Stock
 * Maximum profit from one buy and one sell
 */
public class basic_dsa_two_hundred_sixty_eight {

    // Problem: prices[i] = stock price on day i. Buy one day, sell later. Return max profit.
    // If no profit possible, return 0.

    /**
     * Track min price seen. At each day, profit = price - min, take max.
     * Time O(n), Space O(1)
     */
    public static int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE, maxP = 0;
        for (int p : prices) {
            min = Math.min(min, p);
            maxP = Math.max(maxP, p - min);
        }
        return maxP;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Best Time to Buy and Sell Stock");
        System.out.println("=".repeat(60));

        System.out.println("[7,1,5,3,6,4] -> " + maxProfit(new int[]{7, 1, 5, 3, 6, 4}));
        System.out.println("[7,6,4,3,1] -> " + maxProfit(new int[]{7, 6, 4, 3, 1}));
    }
}
