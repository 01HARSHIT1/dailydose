/**
 * Basic DSA Problems - Best Time to Buy and Sell Stock
 * Find max profit from one buy and one sell
 */
public class basic_dsa_three_hundred_eight {

    // Problem: Array prices where prices[i] is stock price on day i.
    // Return max profit from one buy and one sell. If no profit, return 0.

    /**
     * Track min price seen so far; at each day, profit = price - min.
     * Time O(n), Space O(1)
     */
    public static int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE, profit = 0;
        for (int p : prices) {
            min = Math.min(min, p);
            profit = Math.max(profit, p - min);
        }
        return profit;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Best Time to Buy and Sell Stock");
        System.out.println("=".repeat(60));

        System.out.println("[7,1,5,3,6,4] -> " + maxProfit(new int[]{7, 1, 5, 3, 6, 4}));
        System.out.println("[7,6,4,3,1] -> " + maxProfit(new int[]{7, 6, 4, 3, 1}));
        System.out.println("[2,4,1] -> " + maxProfit(new int[]{2, 4, 1}));
    }
}
