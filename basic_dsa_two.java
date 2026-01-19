/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_two {
    
    // Problem 1: Linear Search
    // Search for an element in an array and return its index
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1; // Element not found
    }
    
    // Problem 2: Sum of Array Elements
    // Calculate the sum of all elements in an array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int sumOfArray(int[] arr) {
        int total = 0;
        for (int num : arr) {
            total += num;
        }
        return total;
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
        System.out.println("Problem 1: Linear Search");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int[] arr1 = {10, 20, 30, 40, 50};
        int target1 = 30;
        int result1 = linearSearch(arr1, target1);
        System.out.print("Array: ");
        printArray(arr1);
        System.out.println();
        System.out.println("Searching for " + target1 + ": Index = " + result1);
        
        // Test Case 2
        int[] arr2 = {5, 8, 12, 16, 23, 38, 56, 72, 91};
        int target2 = 38;
        int result2 = linearSearch(arr2, target2);
        System.out.print("\nArray: ");
        printArray(arr2);
        System.out.println();
        System.out.println("Searching for " + target2 + ": Index = " + result2);
        
        // Test Case 3 - Element not found
        int[] arr3 = {1, 2, 3, 4, 5};
        int target3 = 10;
        int result3 = linearSearch(arr3, target3);
        System.out.print("\nArray: ");
        printArray(arr3);
        System.out.println();
        System.out.println("Searching for " + target3 + ": Index = " + result3 + " (Not found)");
        
        // Test Case 4
        int[] arr4 = {100};
        int target4 = 100;
        int result4 = linearSearch(arr4, target4);
        System.out.print("\nArray: ");
        printArray(arr4);
        System.out.println();
        System.out.println("Searching for " + target4 + ": Index = " + result4);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Sum of Array Elements");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int[] arr5 = {1, 2, 3, 4, 5};
        int sum1 = sumOfArray(arr5);
        System.out.print("Array: ");
        printArray(arr5);
        System.out.println();
        System.out.println("Sum: " + sum1);
        
        // Test Case 2
        int[] arr6 = {10, 20, 30, 40, 50};
        int sum2 = sumOfArray(arr6);
        System.out.print("\nArray: ");
        printArray(arr6);
        System.out.println();
        System.out.println("Sum: " + sum2);
        
        // Test Case 3
        int[] arr7 = {5};
        int sum3 = sumOfArray(arr7);
        System.out.print("\nArray: ");
        printArray(arr7);
        System.out.println();
        System.out.println("Sum: " + sum3);
        
        // Test Case 4 - Negative numbers
        int[] arr8 = {-5, 10, -3, 8, -2};
        int sum4 = sumOfArray(arr8);
        System.out.print("\nArray: ");
        printArray(arr8);
        System.out.println();
        System.out.println("Sum: " + sum4);
        
        // Test Case 5 - Empty array
        int[] arr9 = {};
        int sum5 = sumOfArray(arr9);
        System.out.print("\nArray: ");
        printArray(arr9);
        System.out.println();
        System.out.println("Sum: " + sum5);
    }
}
