"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if Array is Sorted
# Check whether an array is sorted in ascending order
def is_sorted(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if len(arr) <= 1:
        return True
    
    for i in range(1, len(arr)):
        if arr[i] < arr[i - 1]:
            return False
    
    return True


# Problem 2: Find Second Largest Element in Array
# Find the second largest element in an array
def find_second_largest(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if len(arr) < 2:
        return None
    
    largest = float('-inf')
    second_largest = float('-inf')
    
    for num in arr:
        if num > largest:
            second_largest = largest
            largest = num
        elif num > second_largest and num != largest:
            second_largest = num
    
    if second_largest == float('-inf'):
        return None  # All elements are same or only one unique element
    
    return second_largest


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if Array is Sorted")
    print("=" * 60)
    
    # Test Case 1 - Sorted array
    arr1 = [1, 2, 3, 4, 5]
    result1 = is_sorted(arr1)
    print(f"Array: {arr1}")
    print(f"Is sorted: {result1}")
    
    # Test Case 2 - Unsorted array
    arr2 = [5, 2, 8, 1, 9]
    result2 = is_sorted(arr2)
    print(f"\nArray: {arr2}")
    print(f"Is sorted: {result2}")
    
    # Test Case 3 - Single element
    arr3 = [10]
    result3 = is_sorted(arr3)
    print(f"\nArray: {arr3}")
    print(f"Is sorted: {result3}")
    
    # Test Case 4 - Empty array
    arr4 = []
    result4 = is_sorted(arr4)
    print(f"\nArray: {arr4}")
    print(f"Is sorted: {result4}")
    
    # Test Case 5 - Duplicate elements (sorted)
    arr5 = [1, 2, 2, 3, 4]
    result5 = is_sorted(arr5)
    print(f"\nArray: {arr5}")
    print(f"Is sorted: {result5}")
    
    # Test Case 6 - Descending order (not sorted for ascending)
    arr6 = [5, 4, 3, 2, 1]
    result6 = is_sorted(arr6)
    print(f"\nArray: {arr6}")
    print(f"Is sorted: {result6}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find Second Largest Element in Array")
    print("=" * 60)
    
    # Test Case 1
    arr7 = [10, 5, 8, 20, 15]
    result7 = find_second_largest(arr7)
    print(f"Array: {arr7}")
    print(f"Second largest: {result7}")
    
    # Test Case 2
    arr8 = [1, 2, 3, 4, 5]
    result8 = find_second_largest(arr8)
    print(f"\nArray: {arr8}")
    print(f"Second largest: {result8}")
    
    # Test Case 3 - Duplicate largest
    arr9 = [10, 10, 8, 7, 5]
    result9 = find_second_largest(arr9)
    print(f"\nArray: {arr9}")
    print(f"Second largest: {result9}")
    
    # Test Case 4 - All same elements
    arr10 = [5, 5, 5, 5]
    result10 = find_second_largest(arr10)
    print(f"\nArray: {arr10}")
    print(f"Second largest: {result10}")
    
    # Test Case 5 - Two elements
    arr11 = [10, 5]
    result11 = find_second_largest(arr11)
    print(f"\nArray: {arr11}")
    print(f"Second largest: {result11}")
    
    # Test Case 6 - Negative numbers
    arr12 = [-5, -2, -10, -8, -1]
    result12 = find_second_largest(arr12)
    print(f"\nArray: {arr12}")
    print(f"Second largest: {result12}")
