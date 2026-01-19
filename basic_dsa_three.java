/**
 * Basic DSA Problems - Two More Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_three {
    
    // Problem 1: Check if Array is Sorted
    // Check whether an array is sorted in ascending order
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isSorted(int[] arr) {
        if (arr.length <= 1) {
            return true;
        }
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
    // Problem 2: Find Second Largest Element in Array
    // Find the second largest element in an array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer findSecondLargest(int[] arr) {
        if (arr.length < 2) {
            return null;
        }
        
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        
        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }
        
        if (secondLargest == Integer.MIN_VALUE) {
            return null; // All elements are same or only one unique element
        }
        
        return secondLargest;
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
        System.out.println("Problem 1: Check if Array is Sorted");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Sorted array
        int[] arr1 = {1, 2, 3, 4, 5};
        boolean result1 = isSorted(arr1);
        System.out.print("Array: ");
        printArray(arr1);
        System.out.println();
        System.out.println("Is sorted: " + result1);
        
        // Test Case 2 - Unsorted array
        int[] arr2 = {5, 2, 8, 1, 9};
        boolean result2 = isSorted(arr2);
        System.out.print("\nArray: ");
        printArray(arr2);
        System.out.println();
        System.out.println("Is sorted: " + result2);
        
        // Test Case 3 - Single element
        int[] arr3 = {10};
        boolean result3 = isSorted(arr3);
        System.out.print("\nArray: ");
        printArray(arr3);
        System.out.println();
        System.out.println("Is sorted: " + result3);
        
        // Test Case 4 - Empty array
        int[] arr4 = {};
        boolean result4 = isSorted(arr4);
        System.out.print("\nArray: ");
        printArray(arr4);
        System.out.println();
        System.out.println("Is sorted: " + result4);
        
        // Test Case 5 - Duplicate elements (sorted)
        int[] arr5 = {1, 2, 2, 3, 4};
        boolean result5 = isSorted(arr5);
        System.out.print("\nArray: ");
        printArray(arr5);
        System.out.println();
        System.out.println("Is sorted: " + result5);
        
        // Test Case 6 - Descending order (not sorted for ascending)
        int[] arr6 = {5, 4, 3, 2, 1};
        boolean result6 = isSorted(arr6);
        System.out.print("\nArray: ");
        printArray(arr6);
        System.out.println();
        System.out.println("Is sorted: " + result6);
        
        System.out.println("\n" + "=".repeat(60));
        System.out.println("Problem 2: Find Second Largest Element in Array");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int[] arr7 = {10, 5, 8, 20, 15};
        Integer result7 = findSecondLargest(arr7);
        System.out.print("Array: ");
        printArray(arr7);
        System.out.println();
        System.out.println("Second largest: " + (result7 != null ? result7 : "None"));
        
        // Test Case 2
        int[] arr8 = {1, 2, 3, 4, 5};
        Integer result8 = findSecondLargest(arr8);
        System.out.print("\nArray: ");
        printArray(arr8);
        System.out.println();
        System.out.println("Second largest: " + (result8 != null ? result8 : "None"));
        
        // Test Case 3 - Duplicate largest
        int[] arr9 = {10, 10, 8, 7, 5};
        Integer result9 = findSecondLargest(arr9);
        System.out.print("\nArray: ");
        printArray(arr9);
        System.out.println();
        System.out.println("Second largest: " + (result9 != null ? result9 : "None"));
        
        // Test Case 4 - All same elements
        int[] arr10 = {5, 5, 5, 5};
        Integer result10 = findSecondLargest(arr10);
        System.out.print("\nArray: ");
        printArray(arr10);
        System.out.println();
        System.out.println("Second largest: " + (result10 != null ? result10 : "None"));
        
        // Test Case 5 - Two elements
        int[] arr11 = {10, 5};
        Integer result11 = findSecondLargest(arr11);
        System.out.print("\nArray: ");
        printArray(arr11);
        System.out.println();
        System.out.println("Second largest: " + (result11 != null ? result11 : "None"));
        
        // Test Case 6 - Negative numbers
        int[] arr12 = {-5, -2, -10, -8, -1};
        Integer result12 = findSecondLargest(arr12);
        System.out.print("\nArray: ");
        printArray(arr12);
        System.out.println();
        System.out.println("Second largest: " + (result12 != null ? result12 : "None"));
    }
}
