/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_four {
    
    // Problem 1: Find Average of Array Elements
    // Calculate the average of all elements in an array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static double findAverage(int[] arr) {
        if (arr.length == 0) {
            return 0.0;
        }
        
        int total = 0;
        for (int num : arr) {
            total += num;
        }
        
        return (double) total / arr.length;
    }
    
    // Problem 2: Count Even and Odd Numbers in Array
    // Count the number of even and odd numbers in an array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int[] countEvenOdd(int[] arr) {
        int evenCount = 0;
        int oddCount = 0;
        
        for (int num : arr) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        return new int[]{evenCount, oddCount};
    }
    
    // Helper method to print array
    private static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Find Average of Array Elements");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int[] arr1 = {1, 2, 3, 4, 5};
        double avg1 = findAverage(arr1);
        System.out.print("Array: ");
        printArray(arr1);
        System.out.println();
        System.out.println("Average: " + avg1);
        
        // Test Case 2
        int[] arr2 = {10, 20, 30, 40, 50};
        double avg2 = findAverage(arr2);
        System.out.print("\nArray: ");
        printArray(arr2);
        System.out.println();
        System.out.println("Average: " + avg2);
        
        // Test Case 3 - Single element
        int[] arr3 = {15};
        double avg3 = findAverage(arr3);
        System.out.print("\nArray: ");
        printArray(arr3);
        System.out.println();
        System.out.println("Average: " + avg3);
        
        // Test Case 4 - Decimal result
        int[] arr4 = {1, 2, 3, 4};
        double avg4 = findAverage(arr4);
        System.out.print("\nArray: ");
        printArray(arr4);
        System.out.println();
        System.out.println("Average: " + avg4);
        
        // Test Case 5 - Negative numbers
        int[] arr5 = {-5, -10, -15, -20};
        double avg5 = findAverage(arr5);
        System.out.print("\nArray: ");
        printArray(arr5);
        System.out.println();
        System.out.println("Average: " + avg5);
        
        // Test Case 6 - Mixed positive and negative
        int[] arr6 = {-5, 10, -3, 8, -2};
        double avg6 = findAverage(arr6);
        System.out.print("\nArray: ");
        printArray(arr6);
        System.out.println();
        System.out.println("Average: " + avg6);
        
        // Test Case 7 - Empty array
        int[] arr7 = {};
        double avg7 = findAverage(arr7);
        System.out.print("\nArray: ");
        printArray(arr7);
        System.out.println();
        System.out.println("Average: " + avg7);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Count Even and Odd Numbers in Array");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int[] arr8 = {1, 2, 3, 4, 5};
        int[] result1 = countEvenOdd(arr8);
        System.out.print("Array: ");
        printArray(arr8);
        System.out.println();
        System.out.println("Even numbers: " + result1[0] + ", Odd numbers: " + result1[1]);
        
        // Test Case 2
        int[] arr9 = {2, 4, 6, 8, 10};
        int[] result2 = countEvenOdd(arr9);
        System.out.print("\nArray: ");
        printArray(arr9);
        System.out.println();
        System.out.println("Even numbers: " + result2[0] + ", Odd numbers: " + result2[1]);
        
        // Test Case 3
        int[] arr10 = {1, 3, 5, 7, 9};
        int[] result3 = countEvenOdd(arr10);
        System.out.print("\nArray: ");
        printArray(arr10);
        System.out.println();
        System.out.println("Even numbers: " + result3[0] + ", Odd numbers: " + result3[1]);
        
        // Test Case 4 - Mixed with zero
        int[] arr11 = {0, 1, 2, 3, 4, 5};
        int[] result4 = countEvenOdd(arr11);
        System.out.print("\nArray: ");
        printArray(arr11);
        System.out.println();
        System.out.println("Even numbers: " + result4[0] + ", Odd numbers: " + result4[1]);
        
        // Test Case 5 - Negative numbers
        int[] arr12 = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
        int[] result5 = countEvenOdd(arr12);
        System.out.print("\nArray: ");
        printArray(arr12);
        System.out.println();
        System.out.println("Even numbers: " + result5[0] + ", Odd numbers: " + result5[1]);
        
        // Test Case 6 - Single element
        int[] arr13 = {7};
        int[] result6 = countEvenOdd(arr13);
        System.out.print("\nArray: ");
        printArray(arr13);
        System.out.println();
        System.out.println("Even numbers: " + result6[0] + ", Odd numbers: " + result6[1]);
        
        // Test Case 7 - Empty array
        int[] arr14 = {};
        int[] result7 = countEvenOdd(arr14);
        System.out.print("\nArray: ");
        printArray(arr14);
        System.out.println();
        System.out.println("Even numbers: " + result7[0] + ", Odd numbers: " + result7[1]);
    }
}
