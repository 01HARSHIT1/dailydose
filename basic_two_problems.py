"""
Basic DSA Problems - Two Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Reverse an Array
# Reverse the elements of an array in-place
def reverse_array(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left = 0
    right = len(arr) - 1
    
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    
    return arr


# Problem 2: Find Maximum and Minimum in Array
# Find the maximum and minimum elements in an array
def find_max_min(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not arr:
        return None, None
    
    maximum = arr[0]
    minimum = arr[0]
    
    for i in range(1, len(arr)):
        if arr[i] > maximum:
            maximum = arr[i]
        if arr[i] < minimum:
            minimum = arr[i]
    
    return maximum, minimum


# Test cases
if __name__ == "__main__":
    print("=" * 50)
    print("Problem 1: Reverse an Array")
    print("=" * 50)
    
    # Test Case 1
    arr1 = [1, 2, 3, 4, 5]
    print(f"Original array: {arr1}")
    reverse_array(arr1)
    print(f"Reversed array: {arr1}")
    
    # Test Case 2
    arr2 = [10, 20, 30]
    print(f"\nOriginal array: {arr2}")
    reverse_array(arr2)
    print(f"Reversed array: {arr2}")
    
    # Test Case 3
    arr3 = [5]
    print(f"\nOriginal array: {arr3}")
    reverse_array(arr3)
    print(f"Reversed array: {arr3}")
    
    print("\n" + "=" * 50)
    print("Problem 2: Find Maximum and Minimum in Array")
    print("=" * 50)
    
    # Test Case 1
    arr4 = [3, 1, 4, 1, 5, 9, 2, 6]
    max_val, min_val = find_max_min(arr4)
    print(f"Array: {arr4}")
    print(f"Maximum: {max_val}, Minimum: {min_val}")
    
    # Test Case 2
    arr5 = [10, 5, 8, 20, 15]
    max_val, min_val = find_max_min(arr5)
    print(f"\nArray: {arr5}")
    print(f"Maximum: {max_val}, Minimum: {min_val}")
    
    # Test Case 3
    arr6 = [7]
    max_val, min_val = find_max_min(arr6)
    print(f"\nArray: {arr6}")
    print(f"Maximum: {max_val}, Minimum: {min_val}")
    
    # Test Case 4
    arr7 = [5, 5, 5, 5]
    max_val, min_val = find_max_min(arr7)
    print(f"\nArray: {arr7}")
    print(f"Maximum: {max_val}, Minimum: {min_val}")
