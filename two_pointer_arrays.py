"""
Two Pointer Arrays DSA Problems
Collection of problems using two-pointer technique with arrays
"""


# Problem 1: Two Sum (Two Pointers on Sorted Array)
# Find two numbers that add up to target in sorted array
def two_sum_sorted(numbers, target):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(numbers) - 1
    
    while left < right:
        current_sum = numbers[left] + numbers[right]
        if current_sum == target:
            return [left + 1, right + 1]  # 1-indexed
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return []


# Problem 2: Three Sum
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
        # Skip duplicates for first number
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, n - 1
        
        while left < right:
            current_sum = nums[i] + nums[left] + nums[right]
            
            if current_sum < 0:
                left += 1
            elif current_sum > 0:
                right -= 1
            else:
                result.append([nums[i], nums[left], nums[right]])
                
                # Skip duplicates
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                
                left += 1
                right -= 1
    
    return result


# Problem 3: Four Sum
# Find all unique quadruplets that sum to target
def four_sum(nums, target):
    """
    Time Complexity: O(n^3)
    Space Complexity: O(1) excluding output
    """
    nums.sort()
    result = []
    n = len(nums)
    
    for i in range(n - 3):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        for j in range(i + 1, n - 2):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue
            
            left, right = j + 1, n - 1
            
            while left < right:
                current_sum = nums[i] + nums[j] + nums[left] + nums[right]
                
                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    result.append([nums[i], nums[j], nums[left], nums[right]])
                    
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    left += 1
                    right -= 1
    
    return result


# Problem 4: Remove Duplicates from Sorted Array
# Remove duplicates in-place using two pointers
def remove_duplicates(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not nums:
        return 0
    
    write_index = 1
    
    for read_index in range(1, len(nums)):
        if nums[read_index] != nums[read_index - 1]:
            nums[write_index] = nums[read_index]
            write_index += 1
    
    return write_index


# Problem 5: Remove Element
# Remove all instances of val in-place
def remove_element(nums, val):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    write_index = 0
    
    for read_index in range(len(nums)):
        if nums[read_index] != val:
            nums[write_index] = nums[read_index]
            write_index += 1
    
    return write_index


# Problem 6: Move Zeros
# Move all zeros to end while maintaining relative order
def move_zeroes(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    write_index = 0
    
    for read_index in range(len(nums)):
        if nums[read_index] != 0:
            nums[write_index], nums[read_index] = nums[read_index], nums[write_index]
            write_index += 1


# Problem 7: Container With Most Water
# Find two lines that form container with most water
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


# Problem 8: Trapping Rain Water
# Calculate trapped rainwater between bars
def trap_rain_water(height):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not height:
        return 0
    
    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
    water = 0
    
    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1
    
    return water


# Problem 9: Valid Palindrome
# Check if string is palindrome using two pointers
def is_palindrome(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(s) - 1
    
    while left < right:
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True


# Problem 10: Reverse String
# Reverse string using two pointers
def reverse_string(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    s = list(s)
    left, right = 0, len(s) - 1
    
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
    
    return ''.join(s)


# Problem 11: Reverse Words in String
# Reverse order of words using two pointers
def reverse_words(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    words = s.strip().split()
    left, right = 0, len(words) - 1
    
    while left < right:
        words[left], words[right] = words[right], words[left]
        left += 1
        right -= 1
    
    return ' '.join(words)


# Problem 12: Partition Array
# Partition array so elements less than pivot come first
def partition(nums, pivot):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums) - 1
    i = 0
    
    while i <= right:
        if nums[i] < pivot:
            nums[left], nums[i] = nums[i], nums[left]
            left += 1
            i += 1
        elif nums[i] > pivot:
            nums[right], nums[i] = nums[i], nums[right]
            right -= 1
        else:
            i += 1
    
    return left


# Problem 13: Sort Colors (Dutch National Flag)
# Sort array of 0s, 1s, and 2s in-place
def sort_colors(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(nums) - 1
    i = 0
    
    while i <= right:
        if nums[i] == 0:
            nums[left], nums[i] = nums[i], nums[left]
            left += 1
            i += 1
        elif nums[i] == 2:
            nums[right], nums[i] = nums[i], nums[right]
            right -= 1
        else:
            i += 1


# Problem 14: Squares of Sorted Array
# Return squares of sorted array in sorted order
def sorted_squares(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    n = len(nums)
    result = [0] * n
    left, right = 0, n - 1
    idx = n - 1
    
    while left <= right:
        left_square = nums[left] * nums[left]
        right_square = nums[right] * nums[right]
        
        if left_square > right_square:
            result[idx] = left_square
            left += 1
        else:
            result[idx] = right_square
            right -= 1
        idx -= 1
    
    return result


# Problem 15: Merge Sorted Arrays
# Merge two sorted arrays using two pointers
def merge_sorted_arrays(nums1, m, nums2, n):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1)
    """
    i, j, k = m - 1, n - 1, m + n - 1
    
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


# Problem 16: Intersection of Two Arrays
# Find intersection of two sorted arrays
def intersection(nums1, nums2):
    """
    Time Complexity: O(m + n)
    Space Complexity: O(1) excluding output
    """
    i, j = 0, 0
    result = []
    
    while i < len(nums1) and j < len(nums2):
        if nums1[i] == nums2[j]:
            if not result or result[-1] != nums1[i]:
                result.append(nums1[i])
            i += 1
            j += 1
        elif nums1[i] < nums2[j]:
            i += 1
        else:
            j += 1
    
    return result


# Problem 17: Next Permutation
# Find next lexicographical permutation
def next_permutation(nums):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    
    # Find first decreasing element from right
    i = n - 2
    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1
    
    if i >= 0:
        # Find element just larger than nums[i]
        j = n - 1
        while j > i and nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
    
    # Reverse suffix
    left, right = i + 1, n - 1
    while left < right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1


# Problem 18: Boats to Save People
# Find minimum boats needed to save people
def num_rescue_boats(people, limit):
    """
    Time Complexity: O(n log n)
    Space Complexity: O(1)
    """
    people.sort()
    left, right = 0, len(people) - 1
    boats = 0
    
    while left <= right:
        if people[left] + people[right] <= limit:
            left += 1
        right -= 1
        boats += 1
    
    return boats


# Problem 19: Longest Mountain in Array
# Find length of longest mountain subarray
def longest_mountain(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(arr)
    if n < 3:
        return 0
    
    max_length = 0
    i = 1
    
    while i < n - 1:
        if arr[i - 1] < arr[i] > arr[i + 1]:
            left = i - 1
            right = i + 1
            
            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1
            
            max_length = max(max_length, right - left + 1)
            i = right
        else:
            i += 1
    
    return max_length


# Problem 20: Minimum Window Substring
# Find minimum window containing all characters
def min_window_substring(s, t):
    """
    Time Complexity: O(|s| + |t|)
    Space Complexity: O(|s| + |t|)
    """
    if not s or not t:
        return ""
    
    dict_t = {}
    for char in t:
        dict_t[char] = dict_t.get(char, 0) + 1
    
    required = len(dict_t)
    left, right = 0, 0
    formed = 0
    
    window_counts = {}
    ans = float("inf"), None, None
    
    while right < len(s):
        char = s[right]
        window_counts[char] = window_counts.get(char, 0) + 1
        
        if char in dict_t and window_counts[char] == dict_t[char]:
            formed += 1
        
        while left <= right and formed == required:
            char = s[left]
            
            if right - left + 1 < ans[0]:
                ans = (right - left + 1, left, right)
            
            window_counts[char] -= 1
            if char in dict_t and window_counts[char] < dict_t[char]:
                formed -= 1
            
            left += 1
        
        right += 1
    
    return "" if ans[0] == float("inf") else s[ans[1]:ans[2] + 1]


# Test cases
if __name__ == "__main__":
    print("Problem 1 - Two Sum (Sorted):")
    print(two_sum_sorted([2, 7, 11, 15], 9))  # [1, 2]
    
    print("\nProblem 2 - Three Sum:")
    print(three_sum([-1, 0, 1, 2, -1, -4]))
    
    print("\nProblem 3 - Four Sum:")
    print(four_sum([1, 0, -1, 0, -2, 2], 0))
    
    print("\nProblem 4 - Remove Duplicates:")
    nums1 = [1, 1, 2]
    print(f"New length: {remove_duplicates(nums1)}")  # 2
    
    print("\nProblem 5 - Remove Element:")
    nums2 = [3, 2, 2, 3]
    print(f"New length: {remove_element(nums2, 3)}")  # 2
    
    print("\nProblem 7 - Container With Most Water:")
    print(max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]))  # 49
    
    print("\nProblem 8 - Trapping Rain Water:")
    print(trap_rain_water([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))  # 6
    
    print("\nProblem 9 - Valid Palindrome:")
    print(is_palindrome("A man, a plan, a canal: Panama"))  # True
    
    print("\nProblem 10 - Reverse String:")
    print(reverse_string("hello"))  # "olleh"
    
    print("\nProblem 13 - Sort Colors:")
    nums3 = [2, 0, 2, 1, 1, 0]
    sort_colors(nums3)
    print(nums3)  # [0, 0, 1, 1, 2, 2]
    
    print("\nProblem 14 - Squares of Sorted Array:")
    print(sorted_squares([-4, -1, 0, 3, 10]))  # [0, 1, 9, 16, 100]
    
    print("\nProblem 16 - Intersection of Two Arrays:")
    print(intersection([1, 2, 2, 1], [2, 2]))  # [2]
    
    print("\nProblem 18 - Boats to Save People:")
    print(num_rescue_boats([1, 2], 3))  # 1
