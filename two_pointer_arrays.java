import java.util.*;

/**
 * Two Pointer Arrays DSA Problems
 * Collection of problems using two-pointer technique with arrays
 */
public class two_pointer_arrays {
    
    // Problem 1: Two Sum (Two Pointers on Sorted Array)
    // Find two numbers that add up to target in sorted array
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int[] twoSumSorted(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            if (currentSum == target) {
                return new int[]{left + 1, right + 1}; // 1-indexed
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return new int[]{};
    }
    
    // Problem 2: Three Sum
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
            
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum < 0) {
                    left++;
                } else if (currentSum > 0) {
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
    
    // Problem 3: Four Sum
    // Find all unique quadruplets that sum to target
    /**
     * Time Complexity: O(n^3)
     * Space Complexity: O(1) excluding output
     */
    public static List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int left = j + 1, right = n - 1;
                
                while (left < right) {
                    long currentSum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (currentSum < target) {
                        left++;
                    } else if (currentSum > target) {
                        right--;
                    } else {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        
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
        }
        
        return result;
    }
    
    // Problem 4: Remove Duplicates from Sorted Array
    // Remove duplicates in-place using two pointers
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        int writeIndex = 1;
        
        for (int readIndex = 1; readIndex < nums.length; readIndex++) {
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex;
    }
    
    // Problem 5: Remove Element
    // Remove all instances of val in-place
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int removeElement(int[] nums, int val) {
        int writeIndex = 0;
        
        for (int readIndex = 0; readIndex < nums.length; readIndex++) {
            if (nums[readIndex] != val) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex;
    }
    
    // Problem 6: Move Zeros
    // Move all zeros to end while maintaining relative order
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void moveZeroes(int[] nums) {
        int writeIndex = 0;
        
        for (int readIndex = 0; readIndex < nums.length; readIndex++) {
            if (nums[readIndex] != 0) {
                int temp = nums[writeIndex];
                nums[writeIndex] = nums[readIndex];
                nums[readIndex] = temp;
                writeIndex++;
            }
        }
    }
    
    // Problem 7: Container With Most Water
    // Find two lines that form container with most water
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
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
    
    // Problem 8: Trapping Rain Water
    // Calculate trapped rainwater between bars
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int trap(int[] height) {
        if (height.length == 0) {
            return 0;
        }
        
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
    
    // Problem 9: Valid Palindrome
    // Check if string is palindrome using two pointers
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }
            
            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    // Problem 10: Reverse String
    // Reverse string using two pointers
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    // Problem 12: Partition Array
    // Partition array so elements less than pivot come first
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int partition(int[] nums, int pivot) {
        int left = 0, right = nums.length - 1;
        int i = 0;
        
        while (i <= right) {
            if (nums[i] < pivot) {
                swap(nums, left++, i++);
            } else if (nums[i] > pivot) {
                swap(nums, right--, i);
            } else {
                i++;
            }
        }
        
        return left;
    }
    
    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // Problem 13: Sort Colors (Dutch National Flag)
    // Sort array of 0s, 1s, and 2s in-place
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void sortColors(int[] nums) {
        int left = 0, right = nums.length - 1;
        int i = 0;
        
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums, left++, i++);
            } else if (nums[i] == 2) {
                swap(nums, right--, i);
            } else {
                i++;
            }
        }
    }
    
    // Problem 14: Squares of Sorted Array
    // Return squares of sorted array in sorted order
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 0, right = n - 1;
        int idx = n - 1;
        
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[idx] = leftSquare;
                left++;
            } else {
                result[idx] = rightSquare;
                right--;
            }
            idx--;
        }
        
        return result;
    }
    
    // Problem 15: Merge Sorted Arrays
    // Merge two sorted arrays using two pointers
    /**
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
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
    
    // Problem 16: Intersection of Two Arrays
    // Find intersection of two sorted arrays
    /**
     * Time Complexity: O(m + n)
     * Space Complexity: O(1) excluding output
     */
    public static int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) {
                if (result.isEmpty() || result.get(result.size() - 1) != nums1[i]) {
                    result.add(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result.stream().mapToInt(k -> k).toArray();
    }
    
    // Problem 17: Next Permutation
    // Find next lexicographical permutation
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void nextPermutation(int[] nums) {
        int n = nums.length;
        
        // Find first decreasing element from right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Find element just larger than nums[i]
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        
        // Reverse suffix
        int left = i + 1, right = n - 1;
        while (left < right) {
            swap(nums, left++, right--);
        }
    }
    
    // Problem 18: Boats to Save People
    // Find minimum boats needed to save people
    /**
     * Time Complexity: O(n log n)
     * Space Complexity: O(1)
     */
    public static int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int left = 0, right = people.length - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        
        return boats;
    }
    
    // Problem 19: Longest Mountain in Array
    // Find length of longest mountain subarray
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int longestMountain(int[] arr) {
        int n = arr.length;
        if (n < 3) {
            return 0;
        }
        
        int maxLength = 0;
        int i = 1;
        
        while (i < n - 1) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;
                
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }
                
                maxLength = Math.max(maxLength, right - left + 1);
                i = right;
            } else {
                i++;
            }
        }
        
        return maxLength;
    }
    
    // Helper methods for printing
    private static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
    
    private static void printListOfLists(List<List<Integer>> lists) {
        System.out.print("[");
        for (int i = 0; i < lists.size(); i++) {
            System.out.print(lists.get(i));
            if (i < lists.size() - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("Problem 1 - Two Sum (Sorted):");
        printArray(twoSumSorted(new int[]{2, 7, 11, 15}, 9)); // [1, 2]
        
        System.out.println("\nProblem 2 - Three Sum:");
        printListOfLists(threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
        
        System.out.println("\nProblem 4 - Remove Duplicates:");
        int[] nums1 = {1, 1, 2};
        System.out.println("New length: " + removeDuplicates(nums1)); // 2
        
        System.out.println("\nProblem 7 - Container With Most Water:");
        System.out.println(maxArea(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7})); // 49
        
        System.out.println("\nProblem 8 - Trapping Rain Water:");
        System.out.println(trap(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1})); // 6
        
        System.out.println("\nProblem 13 - Sort Colors:");
        int[] nums3 = {2, 0, 2, 1, 1, 0};
        sortColors(nums3);
        printArray(nums3); // [0, 0, 1, 1, 2, 2]
        
        System.out.println("\nProblem 14 - Squares of Sorted Array:");
        printArray(sortedSquares(new int[]{-4, -1, 0, 3, 10})); // [0, 1, 9, 16, 100]
        
        System.out.println("\nProblem 18 - Boats to Save People:");
        System.out.println(numRescueBoats(new int[]{1, 2}, 3)); // 1
    }
}
