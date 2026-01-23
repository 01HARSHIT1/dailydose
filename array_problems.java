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
    }
}
