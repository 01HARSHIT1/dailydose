"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Linear Search
# Search for an element in an array and return its index
def linear_search(arr, target):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1  # Element not found


# Problem 2: Sum of Array Elements
# Calculate the sum of all elements in an array
def sum_of_array(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    total = 0
    for num in arr:
        total += num
    return total


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Linear Search")
    print("=" * 60)
    
    # Test Case 1
    arr1 = [10, 20, 30, 40, 50]
    target1 = 30
    result1 = linear_search(arr1, target1)
    print(f"Array: {arr1}")
    print(f"Searching for {target1}: Index = {result1}")
    
    # Test Case 2
    arr2 = [5, 8, 12, 16, 23, 38, 56, 72, 91]
    target2 = 38
    result2 = linear_search(arr2, target2)
    print(f"\nArray: {arr2}")
    print(f"Searching for {target2}: Index = {result2}")
    
    # Test Case 3 - Element not found
    arr3 = [1, 2, 3, 4, 5]
    target3 = 10
    result3 = linear_search(arr3, target3)
    print(f"\nArray: {arr3}")
    print(f"Searching for {target3}: Index = {result3} (Not found)")
    
    # Test Case 4
    arr4 = [100]
    target4 = 100
    result4 = linear_search(arr4, target4)
    print(f"\nArray: {arr4}")
    print(f"Searching for {target4}: Index = {result4}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Sum of Array Elements")
    print("=" * 60)
    
    # Test Case 1
    arr5 = [1, 2, 3, 4, 5]
    sum1 = sum_of_array(arr5)
    print(f"Array: {arr5}")
    print(f"Sum: {sum1}")
    
    # Test Case 2
    arr6 = [10, 20, 30, 40, 50]
    sum2 = sum_of_array(arr6)
    print(f"\nArray: {arr6}")
    print(f"Sum: {sum2}")
    
    # Test Case 3
    arr7 = [5]
    sum3 = sum_of_array(arr7)
    print(f"\nArray: {arr7}")
    print(f"Sum: {sum3}")
    
    # Test Case 4 - Negative numbers
    arr8 = [-5, 10, -3, 8, -2]
    sum4 = sum_of_array(arr8)
    print(f"\nArray: {arr8}")
    print(f"Sum: {sum4}")
    
    # Test Case 5 - Empty array
    arr9 = []
    sum5 = sum_of_array(arr9)
    print(f"\nArray: {arr9}")
    print(f"Sum: {sum5}")
