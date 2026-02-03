
/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy {

    // Problem: Best Time to Buy and Sell Stock
    // Given prices[i] = price on day i, find max profit from one buy and one sell.
    // You must buy before you sell. Return 0 if no profit possible.
    // Example: [7,1,5,3,6,4] -> 5 (buy at 1, sell at 6)

    /**
     * Max profit with one transaction (buy once, sell once)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
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

        int[] p1 = { 7, 1, 5, 3, 6, 4 };
        System.out.println("prices = " + Arrays.toString(p1) + " -> " + maxProfit(p1));

        int[] p2 = { 7, 6, 4, 3, 1 };
        System.out.println("prices = " + Arrays.toString(p2) + " -> " + maxProfit(p2));

        int[] p3 = { 1, 2 };
        System.out.println("prices = " + Arrays.toString(p3) + " -> " + maxProfit(p3));
    }
}
