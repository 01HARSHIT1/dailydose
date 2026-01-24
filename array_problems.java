import java.util.*;

/**
 * Array DSA Interview Problems
 * Collection of common array problems with solutions
 */
public class array_problems {
    
    // Problem 1: Two Sum
    // Given an array of integers nums and an integer target, 
    // return indices of the two numbers such that they add up to target.
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[]{numMap.get(complement), i};
            }
            numMap.put(nums[i], i);
        }
        return new int[]{};
    }
    
    // Problem 2: Maximum Subarray (Kadane's Algorithm)
    // Find the contiguous subarray with the largest sum
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int maxSubarray(int[] nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }
        return maxSum;
    }
    
    // Problem 3: Best Time to Buy and Sell Stock
    // Find the maximum profit from buying and selling stock once
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.length; i++) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
    
    // Problem 4: Contains Duplicate
    // Check if array contains any duplicates
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
        }
        return false;
    }
    
    // Problem 5: Product of Array Except Self
    // Return an array output such that output[i] is equal to the 
    // product of all elements of nums except nums[i]
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1) excluding output array
     */
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, 1);
        
        // Calculate left products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Calculate right products and multiply
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
    
    // Problem 6: Maximum Product Subarray
    // Find the contiguous subarray with the largest product
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int maxProductSubarray(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {
                int temp = maxProd;
                maxProd = minProd;
                minProd = temp;
            }
            
            maxProd = Math.max(nums[i], maxProd * nums[i]);
            minProd = Math.min(nums[i], minProd * nums[i]);
            result = Math.max(result, maxProd);
        }
        
        return result;
    }
    
    // Problem 7: Find Minimum in Rotated Sorted Array
    // Find the minimum element in a rotated sorted array
    /**
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int findMinRotated(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
    
    // Problem 8: Search in Rotated Sorted Array
    // Search for target in rotated sorted array
    /**
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int searchRotated(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
    
    // Problem 9: 3Sum
    // Find all unique triplets that sum to zero
    /**
     * Time Complexity: O(n^2)
     * Space Complexity: O(1) excluding output
     */
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                
                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
    
    // Problem 10: Container With Most Water
    // Find two lines that together with x-axis forms a container with most water
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxWater = 0;
        
        while (left < right) {
            int width = right - left;
            int currentArea = Math.min(height[left], height[right]) * width;
            maxWater = Math.max(maxWater, currentArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
    
    // Problem 11: Merge Sorted Arrays
    // Merge two sorted arrays in-place (nums1 has enough space)
    /**
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static void mergeSortedArrays(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    
    // Problem 12: Rotate Array
    // Rotate array to the right by k steps
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void rotateArray(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    
    private static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    
    // Problem 13: Find First Repeating Element
    // Given an array of integers, find the first element that appears more than once
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int findFirstRepeating(int[] nums) {
        Map<Integer, Integer> countMap = new HashMap<>();
        
        // Count occurrences of each element
        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        
        // Find first element with count > 1
        for (int num : nums) {
            if (countMap.get(num) > 1) {
                return num;
            }
        }
        
        return -1; // No repeating element found
    }
    
    // Problem 14: Find Missing Number
    // Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
    // find the one that is missing from the array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int findMissingNumber(int[] nums) {
        int n = nums.length;
        int expectedSum = n * (n + 1) / 2; // Sum of numbers from 0 to n
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
    
    // Problem 15: Single Number
    // Given a non-empty array of integers where every element appears twice except for one,
    // find the single one
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
    
    // Problem 16: Majority Element
    // Given an array of size n, find the element that appears more than n/2 times
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     * Uses Boyer-Moore Voting Algorithm
     */
    public static int majorityElement(int[] nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
    
    // Problem 17: Count Occurrences of an Element
    // Given an array and a target value, count how many times the target appears in the array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int countOccurrences(int[] nums, int target) {
        int count = 0;
        for (int num : nums) {
            if (num == target) {
                count++;
            }
        }
        return count;
    }
    
    // Problem 18: Linear Search
    // Given an array and a target value, return the index of the target if found, otherwise -1
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int linearSearch(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    // Problem 19: Binary Search (Any Occurrence)
    // Given a sorted array and a target value, return the index of the target if found, otherwise -1
    /**
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static int binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    // Problem 20: Find Maximum Element
    // Given an array, find the maximum element
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int findMax(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array must not be empty");
        }
        
        int maximum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > maximum) {
                maximum = nums[i];
            }
        }
        return maximum;
    }
    
    // Problem 21: Check if Array is Sorted (Non-decreasing)
    // Given an array, check if it is sorted in non-decreasing order
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isSorted(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    // Problem 22: Find Minimum Element
    // Given an array, find the minimum element
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int findMinElement(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array must not be empty");
        }
        
        int minimum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
            }
        }
        return minimum;
    }
    
    // Problem 23: Sum of Array Elements
    // Given an array, find the sum of all elements
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int sumArray(int[] nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        return total;
    }
    
    // Problem 24: Reverse Array
    // Given an array, reverse it in-place
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void reverseArray(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    
    // Problem 25: Count Even Numbers in Array
    // Given an array, count how many numbers are even
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int countEvens(int[] nums) {
        int count = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                count++;
            }
        }
        return count;
    }
    
    // Problem 26: Range of Array (Max - Min)
    // Given an array, find the difference between maximum and minimum elements
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int arrayRange(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array must not be empty");
        }
        
        int minimum = nums[0];
        int maximum = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
            }
            if (nums[i] > maximum) {
                maximum = nums[i];
            }
        }
        
        return maximum - minimum;
    }
    
    // Problem 27: Count Odd Numbers in Array
    // Given an array, count how many numbers are odd
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int countOdds(int[] nums) {
        int count = 0;
        for (int num : nums) {
            if (num % 2 != 0) {
                count++;
            }
        }
        return count;
    }
    
    // Problem 28: Find Average of Array Elements
    // Given an array, find the average of all elements
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static double findAverage(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array must not be empty");
        }
        
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        return (double) sum / nums.length;
    }
    
    // Problem 29: Find Second Largest Element
    // Given an array, find the second largest element
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int findSecondLargest(int[] nums) {
        if (nums == null || nums.length < 2) {
            throw new IllegalArgumentException("Array must have at least 2 elements");
        }
        
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        
        for (int num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }
        
        if (secondLargest == Integer.MIN_VALUE) {
            throw new IllegalArgumentException("No second largest element found");
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
        System.out.println("]");
    }
    
    // Test cases
    public static void main(String[] args) {
        // Test Two Sum
        System.out.println("Problem 1 - Two Sum:");
        printArray(twoSum(new int[]{2, 7, 11, 15}, 9)); // Output: [0, 1]
        
        // Test Maximum Subarray
        System.out.println("\nProblem 2 - Maximum Subarray:");
        System.out.println(maxSubarray(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4})); // Output: 6
        
        // Test Max Profit
        System.out.println("\nProblem 3 - Best Time to Buy and Sell Stock:");
        System.out.println(maxProfit(new int[]{7, 1, 5, 3, 6, 4})); // Output: 5
        
        // Test Contains Duplicate
        System.out.println("\nProblem 4 - Contains Duplicate:");
        System.out.println(containsDuplicate(new int[]{1, 2, 3, 1})); // Output: true
        
        // Test Product Except Self
        System.out.println("\nProblem 5 - Product of Array Except Self:");
        printArray(productExceptSelf(new int[]{1, 2, 3, 4})); // Output: [24, 12, 8, 6]
        
        // Test Max Product Subarray
        System.out.println("\nProblem 6 - Maximum Product Subarray:");
        System.out.println(maxProductSubarray(new int[]{2, 3, -2, 4})); // Output: 6
        
        // Test Find Min Rotated
        System.out.println("\nProblem 7 - Find Minimum in Rotated Sorted Array:");
        System.out.println(findMinRotated(new int[]{3, 4, 5, 1, 2})); // Output: 1
        
        // Test Search Rotated
        System.out.println("\nProblem 8 - Search in Rotated Sorted Array:");
        System.out.println(searchRotated(new int[]{4, 5, 6, 7, 0, 1, 2}, 0)); // Output: 4
        
        // Test 3Sum
        System.out.println("\nProblem 9 - 3Sum:");
        System.out.println(threeSum(new int[]{-1, 0, 1, 2, -1, -4})); // Output: [[-1, -1, 2], [-1, 0, 1]]
        
        // Test Max Area
        System.out.println("\nProblem 10 - Container With Most Water:");
        System.out.println(maxArea(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7})); // Output: 49
        
        // Test Merge Sorted Arrays
        System.out.println("\nProblem 11 - Merge Sorted Arrays:");
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        mergeSortedArrays(nums1, 3, new int[]{2, 5, 6}, 3);
        printArray(nums1); // Output: [1, 2, 2, 3, 5, 6]
        
        // Test Rotate Array
        System.out.println("\nProblem 12 - Rotate Array:");
        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        rotateArray(nums, 3);
        printArray(nums); // Output: [5, 6, 7, 1, 2, 3, 4]
        
        // Test Find First Repeating
        System.out.println("\nProblem 13 - Find First Repeating Element:");
        System.out.println(findFirstRepeating(new int[]{10, 5, 3, 4, 3, 5, 6})); // Output: 5
        
        // Test Find Missing Number
        System.out.println("\nProblem 14 - Find Missing Number:");
        System.out.println(findMissingNumber(new int[]{3, 0, 1})); // Output: 2
        
        // Test Single Number
        System.out.println("\nProblem 15 - Single Number:");
        System.out.println(singleNumber(new int[]{4, 1, 2, 1, 2})); // Output: 4
        
        // Test Majority Element
        System.out.println("\nProblem 16 - Majority Element:");
        System.out.println(majorityElement(new int[]{3, 2, 3})); // Output: 3
        
        // Test Count Occurrences
        System.out.println("\nProblem 17 - Count Occurrences of Element:");
        System.out.println(countOccurrences(new int[]{1, 2, 2, 3, 2, 4}, 2)); // Output: 3
        
        // Test Linear Search
        System.out.println("\nProblem 18 - Linear Search:");
        System.out.println(linearSearch(new int[]{4, 2, 7, 1, 9}, 7)); // Output: 2
        
        // Test Binary Search
        System.out.println("\nProblem 19 - Binary Search (Any Occurrence):");
        System.out.println(binarySearch(new int[]{1, 2, 3, 4, 5, 6}, 4)); // Output: 3
        
        // Test Find Maximum Element
        System.out.println("\nProblem 20 - Find Maximum Element:");
        System.out.println(findMax(new int[]{3, 1, 7, 0, 5})); // Output: 7
        
        // Test Check if Array is Sorted
        System.out.println("\nProblem 21 - Check if Array is Sorted:");
        System.out.println(isSorted(new int[]{1, 2, 2, 3, 5})); // Output: true
        
        // Test Find Minimum Element
        System.out.println("\nProblem 22 - Find Minimum Element:");
        System.out.println(findMinElement(new int[]{3, 1, 7, 0, 5})); // Output: 0
        
        // Test Sum of Array Elements
        System.out.println("\nProblem 23 - Sum of Array Elements:");
        System.out.println(sumArray(new int[]{1, 2, 3, 4, 5})); // Output: 15
        
        // Test Reverse Array
        System.out.println("\nProblem 24 - Reverse Array:");
        int[] nums24 = {1, 2, 3, 4, 5};
        reverseArray(nums24);
        printArray(nums24); // Output: [5, 4, 3, 2, 1]
        
        // Test Count Even Numbers in Array
        System.out.println("\nProblem 25 - Count Even Numbers in Array:");
        System.out.println(countEvens(new int[]{1, 2, 3, 4, 6})); // Output: 3
        
        // Test Range of Array (Max - Min)
        System.out.println("\nProblem 26 - Range of Array (Max - Min):");
        System.out.println(arrayRange(new int[]{3, 1, 7, 0, 5})); // Output: 7
        
        // Test Count Odd Numbers in Array
        System.out.println("\nProblem 27 - Count Odd Numbers in Array:");
        System.out.println(countOdds(new int[]{1, 2, 3, 4, 5})); // Output: 3
        
        // Test Find Average of Array Elements
        System.out.println("\nProblem 28 - Find Average of Array Elements:");
        System.out.println(findAverage(new int[]{1, 2, 3, 4, 5})); // Output: 3.0
        
        // Test Find Second Largest Element
        System.out.println("\nProblem 29 - Find Second Largest Element:");
        System.out.println(findSecondLargest(new int[]{3, 1, 7, 0, 5})); // Output: 5
    }
}
