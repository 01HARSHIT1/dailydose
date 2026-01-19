/**
 * Basic DSA Problems - Two Fundamental Questions
 * Simple and essential DSA problems for beginners
 */
public class basic_two_problems {
    
    // Problem 1: Reverse an Array
    // Reverse the elements of an array in-place
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void reverseArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left < right) {
            // Swap elements
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            
            left++;
            right--;
        }
    }
    
    // Problem 2: Find Maximum and Minimum in Array
    // Find the maximum and minimum elements in an array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int[] findMaxMin(int[] arr) {
        if (arr.length == 0) {
            return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        }
        
        int maximum = arr[0];
        int minimum = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > maximum) {
                maximum = arr[i];
            }
            if (arr[i] < minimum) {
                minimum = arr[i];
            }
        }
        
        return new int[]{maximum, minimum};
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
        System.out.println("]");
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(50));
        System.out.println("Problem 1: Reverse an Array");
        System.out.println("=".repeat(50));
        
        // Test Case 1
        int[] arr1 = {1, 2, 3, 4, 5};
        System.out.print("Original array: ");
        printArray(arr1);
        reverseArray(arr1);
        System.out.print("Reversed array: ");
        printArray(arr1);
        
        // Test Case 2
        int[] arr2 = {10, 20, 30};
        System.out.print("\nOriginal array: ");
        printArray(arr2);
        reverseArray(arr2);
        System.out.print("Reversed array: ");
        printArray(arr2);
        
        // Test Case 3
        int[] arr3 = {5};
        System.out.print("\nOriginal array: ");
        printArray(arr3);
        reverseArray(arr3);
        System.out.print("Reversed array: ");
        printArray(arr3);
        
        System.out.println("\n" + "=".repeat(50));
        System.out.println("Problem 2: Find Maximum and Minimum in Array");
        System.out.println("=".repeat(50));
        
        // Test Case 1
        int[] arr4 = {3, 1, 4, 1, 5, 9, 2, 6};
        System.out.print("Array: ");
        printArray(arr4);
        int[] result1 = findMaxMin(arr4);
        System.out.println("Maximum: " + result1[0] + ", Minimum: " + result1[1]);
        
        // Test Case 2
        int[] arr5 = {10, 5, 8, 20, 15};
        System.out.print("\nArray: ");
        printArray(arr5);
        int[] result2 = findMaxMin(arr5);
        System.out.println("Maximum: " + result2[0] + ", Minimum: " + result2[1]);
        
        // Test Case 3
        int[] arr6 = {7};
        System.out.print("\nArray: ");
        printArray(arr6);
        int[] result3 = findMaxMin(arr6);
        System.out.println("Maximum: " + result3[0] + ", Minimum: " + result3[1]);
        
        // Test Case 4
        int[] arr7 = {5, 5, 5, 5};
        System.out.print("\nArray: ");
        printArray(arr7);
        int[] result4 = findMaxMin(arr7);
        System.out.println("Maximum: " + result4[0] + ", Minimum: " + result4[1]);
    }
}
