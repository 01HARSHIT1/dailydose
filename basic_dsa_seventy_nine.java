/**
 * Basic DSA Problems - Best Time to Buy and Sell Stock
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_nine {

    // Problem: One transaction allowed. Find max profit (buy low, sell later).
    // Example: [7,1,5,3,6,4] -> 5 (buy 1, sell 6)

    /**
     * Track min price so far; at each day, profit = price - min, update max profit.
     * Time O(n), Space O(1)
     */
    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2) return 0;
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.length; i++) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Best Time to Buy and Sell Stock");
        System.out.println("=".repeat(60));

        int[] a1 = { 7, 1, 5, 3, 6, 4 };
        System.out.println("Prices: " + Arrays.toString(a1) + " -> Max profit: " + maxProfit(a1));

        int[] a2 = { 7, 6, 4, 3, 1 };
        System.out.println("Prices: " + Arrays.toString(a2) + " -> Max profit: " + maxProfit(a2));

        int[] a3 = { 1, 2 };
        System.out.println("Prices: " + Arrays.toString(a3) + " -> Max profit: " + maxProfit(a3));
    }
}
