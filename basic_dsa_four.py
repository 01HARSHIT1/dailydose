"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Find Average of Array Elements
# Calculate the average of all elements in an array
def find_average(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if len(arr) == 0:
        return 0.0
    
    total = sum(arr)
    return total / len(arr)


# Problem 2: Count Even and Odd Numbers in Array
# Count the number of even and odd numbers in an array
def count_even_odd(arr):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    even_count = 0
    odd_count = 0
    
    for num in arr:
        if num % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
    
    return even_count, odd_count


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Find Average of Array Elements")
    print("=" * 60)
    
    # Test Case 1
    arr1 = [1, 2, 3, 4, 5]
    avg1 = find_average(arr1)
    print(f"Array: {arr1}")
    print(f"Average: {avg1}")
    
    # Test Case 2
    arr2 = [10, 20, 30, 40, 50]
    avg2 = find_average(arr2)
    print(f"\nArray: {arr2}")
    print(f"Average: {avg2}")
    
    # Test Case 3 - Single element
    arr3 = [15]
    avg3 = find_average(arr3)
    print(f"\nArray: {arr3}")
    print(f"Average: {avg3}")
    
    # Test Case 4 - Decimal result
    arr4 = [1, 2, 3, 4]
    avg4 = find_average(arr4)
    print(f"\nArray: {arr4}")
    print(f"Average: {avg4}")
    
    # Test Case 5 - Negative numbers
    arr5 = [-5, -10, -15, -20]
    avg5 = find_average(arr5)
    print(f"\nArray: {arr5}")
    print(f"Average: {avg5}")
    
    # Test Case 6 - Mixed positive and negative
    arr6 = [-5, 10, -3, 8, -2]
    avg6 = find_average(arr6)
    print(f"\nArray: {arr6}")
    print(f"Average: {avg6}")
    
    # Test Case 7 - Empty array
    arr7 = []
    avg7 = find_average(arr7)
    print(f"\nArray: {arr7}")
    print(f"Average: {avg7}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Count Even and Odd Numbers in Array")
    print("=" * 60)
    
    # Test Case 1
    arr8 = [1, 2, 3, 4, 5]
    even1, odd1 = count_even_odd(arr8)
    print(f"Array: {arr8}")
    print(f"Even numbers: {even1}, Odd numbers: {odd1}")
    
    # Test Case 2
    arr9 = [2, 4, 6, 8, 10]
    even2, odd2 = count_even_odd(arr9)
    print(f"\nArray: {arr9}")
    print(f"Even numbers: {even2}, Odd numbers: {odd2}")
    
    # Test Case 3
    arr10 = [1, 3, 5, 7, 9]
    even3, odd3 = count_even_odd(arr10)
    print(f"\nArray: {arr10}")
    print(f"Even numbers: {even3}, Odd numbers: {odd3}")
    
    # Test Case 4 - Mixed with zero
    arr11 = [0, 1, 2, 3, 4, 5]
    even4, odd4 = count_even_odd(arr11)
    print(f"\nArray: {arr11}")
    print(f"Even numbers: {even4}, Odd numbers: {odd4}")
    
    # Test Case 5 - Negative numbers
    arr12 = [-4, -3, -2, -1, 0, 1, 2, 3, 4]
    even5, odd5 = count_even_odd(arr12)
    print(f"\nArray: {arr12}")
    print(f"Even numbers: {even5}, Odd numbers: {odd5}")
    
    # Test Case 6 - Single element
    arr13 = [7]
    even6, odd6 = count_even_odd(arr13)
    print(f"\nArray: {arr13}")
    print(f"Even numbers: {even6}, Odd numbers: {odd6}")
    
    # Test Case 7 - Empty array
    arr14 = []
    even7, odd7 = count_even_odd(arr14)
    print(f"\nArray: {arr14}")
    print(f"Even numbers: {even7}, Odd numbers: {odd7}")
