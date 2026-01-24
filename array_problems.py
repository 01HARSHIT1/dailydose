"""
Array DSA Interview Problems
Collection of common array problems with solutions
"""


# Problem 1: Two Sum
# Given an array of integers nums and an integer target, 
# return indices of the two numbers such that they add up to target.
def two_sum(nums, target):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    num_map = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i
    return []


# Problem 2: Maximum Subarray (Kadane's Algorithm)
# Find the contiguous subarray with the largest sum
def max_subarray(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    max_sum = current_sum = nums[0]
    for num in nums[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum


# Problem 3: Best Time to Buy and Sell Stock
# Find the maximum profit from buying and selling stock once
def max_profit(prices):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not prices:
        return 0
    
    min_price = prices[0]
    max_profit = 0
    
    for price in prices[1:]:
        max_profit = max(max_profit, price - min_price)
        min_price = min(min_price, price)
    
    return max_profit


# Problem 4: Contains Duplicate
# Check if array contains any duplicates
def contains_duplicate(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False


# Problem 5: Product of Array Except Self
# Return an array output such that output[i] is equal to the 
# product of all elements of nums except nums[i]
def product_except_self(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1) excluding output array
    """
    n = len(nums)
    result = [1] * n
    
    # Calculate left products
    for i in range(1, n):
        result[i] = result[i-1] * nums[i-1]
    
    # Calculate right products and multiply
    right_product = 1
    for i in range(n-1, -1, -1):
        result[i] *= right_product
        right_product *= nums[i]
    
    return result


# Problem 6: Maximum Product Subarray
# Find the contiguous subarray with the largest product
def max_product_subarray(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not nums:
        return 0
    
    max_prod = min_prod = result = nums[0]
    
    for num in nums[1:]:
        if num < 0:
            max_prod, min_prod = min_prod, max_prod
        
        max_prod = max(num, max_prod * num)
        min_prod = min(num, min_prod * num)
        result = max(result, max_prod)
    
    return result


# Problem 7: Find Minimum in Rotated Sorted Array
# Find the minimum element in a rotated sorted array
def find_min_rotated(nums):
    """
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums) - 1
    
    while left < right:
        mid = (left + right) // 2
        if nums[mid] > nums[right]:
            left = mid + 1
        else:
            right = mid
    
    return nums[left]


# Problem 8: Search in Rotated Sorted Array
# Search for target in rotated sorted array
def search_rotated(nums, target):
    """
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if nums[mid] == target:
            return mid
        
        # Left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        # Right half is sorted
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    
    return -1


# Problem 9: 3Sum
# Find all unique triplets that sum to zero
def three_sum(nums):
    """
    Time Complexity: O(n^2)
    Space Complexity: O(1) excluding output
    """
    nums.sort()
    result = []
    n = len(nums)
    
    for i in range(n - 2):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        
        left, right = i + 1, n - 1
        
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            
            if total < 0:
                left += 1
            elif total > 0:
                right -= 1
            else:
                result.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left+1]:
                    left += 1
                while left < right and nums[right] == nums[right-1]:
                    right -= 1
                left += 1
                right -= 1
    
    return result


# Problem 10: Container With Most Water
# Find two lines that together with x-axis forms a container with most water
def max_area(height):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(height) - 1
    max_water = 0
    
    while left < right:
        width = right - left
        current_area = min(height[left], height[right]) * width
        max_water = max(max_water, current_area)
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_water


# Problem 11: Merge Sorted Arrays
# Merge two sorted arrays in-place (nums1 has enough space)
def merge_sorted_arrays(nums1, m, nums2, n):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    i = m - 1
    j = n - 1
    k = m + n - 1
    
    while i >= 0 and j >= 0:
        if nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1
    
    while j >= 0:
        nums1[k] = nums2[j]
        j -= 1
        k -= 1


# Problem 12: Rotate Array
# Rotate array to the right by k steps
def rotate_array(nums, k):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    k = k % n
    
    def reverse(arr, start, end):
        while start < end:
            arr[start], arr[end] = arr[end], arr[start]
            start += 1
            end -= 1
    
    reverse(nums, 0, n - 1)
    reverse(nums, 0, k - 1)
    reverse(nums, k, n - 1)


# Problem 13: Find First Repeating Element
# Find the first element that appears more than once in the array
def find_first_repeating(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    count_map = {}
    
    # Count frequency of each element
    for num in nums:
        count_map[num] = count_map.get(num, 0) + 1
    
    # Find first element with count > 1
    for num in nums:
        if count_map[num] > 1:
            return num
    
    return -1  # No repeating element found


# Problem 14: Find Missing Number
# Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
# find the one that is missing from the array
def find_missing_number(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    expected_sum = n * (n + 1) // 2  # Sum of numbers from 0 to n
    actual_sum = sum(nums)
    
    return expected_sum - actual_sum


# Problem 15: Single Number
# Given a non-empty array of integers where every element appears twice except for one,
# find the single one
def single_number(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    result = 0
    for num in nums:
        result ^= num
    return result


# Problem 16: Majority Element
# Given an array of size n, find the element that appears more than n/2 times
def majority_element(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    Uses Boyer-Moore Voting Algorithm
    """
    candidate = None
    count = 0
    
    for num in nums:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1
    
    return candidate


# Test cases
if __name__ == "__main__":
    # Test Two Sum
    print("Problem 1 - Two Sum:")
    print(two_sum([2, 7, 11, 15], 9))  # Output: [0, 1]
    
    # Test Maximum Subarray
    print("\nProblem 2 - Maximum Subarray:")
    print(max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  # Output: 6
    
    # Test Max Profit
    print("\nProblem 3 - Best Time to Buy and Sell Stock:")
    print(max_profit([7, 1, 5, 3, 6, 4]))  # Output: 5
    
    # Test Contains Duplicate
    print("\nProblem 4 - Contains Duplicate:")
    print(contains_duplicate([1, 2, 3, 1]))  # Output: True
    
    # Test Product Except Self
    print("\nProblem 5 - Product of Array Except Self:")
    print(product_except_self([1, 2, 3, 4]))  # Output: [24, 12, 8, 6]
    
    # Test Max Product Subarray
    print("\nProblem 6 - Maximum Product Subarray:")
    print(max_product_subarray([2, 3, -2, 4]))  # Output: 6
    
    # Test Find Min Rotated
    print("\nProblem 7 - Find Minimum in Rotated Sorted Array:")
    print(find_min_rotated([3, 4, 5, 1, 2]))  # Output: 1
    
    # Test Search Rotated
    print("\nProblem 8 - Search in Rotated Sorted Array:")
    print(search_rotated([4, 5, 6, 7, 0, 1, 2], 0))  # Output: 4
    
    # Test 3Sum
    print("\nProblem 9 - 3Sum:")
    print(three_sum([-1, 0, 1, 2, -1, -4]))  # Output: [[-1, -1, 2], [-1, 0, 1]]
    
    # Test Max Area
    print("\nProblem 10 - Container With Most Water:")
    print(max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]))  # Output: 49
    
    # Test Merge Sorted Arrays
    print("\nProblem 11 - Merge Sorted Arrays:")
    nums1 = [1, 2, 3, 0, 0, 0]
    merge_sorted_arrays(nums1, 3, [2, 5, 6], 3)
    print(nums1)  # Output: [1, 2, 2, 3, 5, 6]
    
    # Test Rotate Array
    print("\nProblem 12 - Rotate Array:")
    nums = [1, 2, 3, 4, 5, 6, 7]
    rotate_array(nums, 3)
    print(nums)  # Output: [5, 6, 7, 1, 2, 3, 4]
    
    # Test Find First Repeating
    print("\nProblem 13 - Find First Repeating Element:")
    print(find_first_repeating([10, 5, 3, 4, 3, 5, 6]))  # Output: 5
    
    # Test Find Missing Number
    print("\nProblem 14 - Find Missing Number:")
    print(find_missing_number([3, 0, 1]))  # Output: 2
    
    # Test Single Number
    print("\nProblem 15 - Single Number:")
    print(single_number([4, 1, 2, 1, 2]))  # Output: 4
    
    # Test Majority Element
    print("\nProblem 16 - Majority Element:")
    print(majority_element([3, 2, 3]))  # Output: 3
