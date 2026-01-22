"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Perfect Cube
# A perfect cube is a number that can be expressed as the cube of an integer
# Example: 8 = 2³, 27 = 3³, 64 = 4³

def is_perfect_cube_math(n):
    """
    Check if a number is perfect cube using math library
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
    
    import math
    cube_root = round(math.pow(n, 1/3))
    return cube_root ** 3 == n


def is_perfect_cube_binary_search(n):
    """
    Check if a number is perfect cube using binary search
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
    if n == 0 or n == 1:
        return True
    
    left, right = 1, n
    
    while left <= right:
        mid = (left + right) // 2
        cube = mid * mid * mid
        
        if cube == n:
            return True
        elif cube < n:
            left = mid + 1
        else:
            right = mid - 1
    
    return False


def get_cube_root(n):
    """
    Get the cube root if number is perfect cube
    Returns cube root if perfect cube, None otherwise
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
        is_negative = True
    else:
        is_negative = False
    
    if n == 0:
        return 0
    if n == 1:
        return -1 if is_negative else 1
    
    left, right = 1, n
    
    while left <= right:
        mid = (left + right) // 2
        cube = mid * mid * mid
        
        if cube == n:
            return -mid if is_negative else mid
        elif cube < n:
            left = mid + 1
        else:
            right = mid - 1
    
    return None


def get_perfect_cubes_in_range(start, end):
    """
    Find all perfect cubes in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of perfect cubes
    """
    perfect_cubes = []
    
    for num in range(start, end + 1):
        if is_perfect_cube_binary_search(num):
            perfect_cubes.append(num)
    
    return perfect_cubes


# Problem 2: Find Sum of First N Even Numbers
# Sum of first n even numbers = n(n+1)
# Example: 2 + 4 + 6 + 8 = 20 = 4 × 5

def sum_of_even_numbers_iterative(n):
    """
    Find sum of first n even numbers using iteration
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    
    total = 0
    even = 2
    
    for i in range(n):
        total += even
        even += 2
    
    return total


def sum_of_even_numbers_formula(n):
    """
    Find sum of first n even numbers using formula
    Sum = n(n+1)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    return n * (n + 1)


def sum_of_even_numbers_recursive(n):
    """
    Find sum of first n even numbers using recursion
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n <= 0:
        return 0
    if n == 1:
        return 2
    
    # nth even number = 2n
    nth_even = 2 * n
    return nth_even + sum_of_even_numbers_recursive(n - 1)


def get_first_n_even_numbers(n):
    """
    Get list of first n even numbers
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if n <= 0:
        return []
    
    even_numbers = []
    even = 2
    
    for i in range(n):
        even_numbers.append(even)
        even += 2
    
    return even_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Perfect Cube")
    print("=" * 60)
    
    # Test Case 1 - Perfect cube 8
    num1 = 8
    result1_math = is_perfect_cube_math(num1)
    result1_bs = is_perfect_cube_binary_search(num1)
    cube_root1 = get_cube_root(num1)
    print(f"Number: {num1}")
    print(f"Is perfect cube (math): {result1_math}")
    print(f"Is perfect cube (binary search): {result1_bs}")
    if cube_root1 is not None:
        print(f"Cube root: {cube_root1}")
    
    # Test Case 2 - Perfect cube 27
    num2 = 27
    result2 = is_perfect_cube_binary_search(num2)
    cube_root2 = get_cube_root(num2)
    print(f"\nNumber: {num2}")
    print(f"Is perfect cube: {result2}")
    if cube_root2 is not None:
        print(f"Cube root: {cube_root2}")
    
    # Test Case 3 - Not perfect cube
    num3 = 25
    result3 = is_perfect_cube_binary_search(num3)
    cube_root3 = get_cube_root(num3)
    print(f"\nNumber: {num3}")
    print(f"Is perfect cube: {result3}")
    if cube_root3 is None:
        print("Not a perfect cube")
    
    # Test Case 4 - Perfect cube 1
    num4 = 1
    result4 = is_perfect_cube_binary_search(num4)
    cube_root4 = get_cube_root(num4)
    print(f"\nNumber: {num4}")
    print(f"Is perfect cube: {result4}")
    if cube_root4 is not None:
        print(f"Cube root: {cube_root4}")
    
    # Test Case 5 - Find perfect cubes in range
    start = 1
    end = 100
    perfect_cubes = get_perfect_cubes_in_range(start, end)
    print(f"\nPerfect cubes in range [{start}, {end}]:")
    print(perfect_cubes)
    print(f"Count: {len(perfect_cubes)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find Sum of First N Even Numbers")
    print("=" * 60)
    
    # Test Case 1 - Sum of first 4 even numbers
    n1 = 4
    result1_iter = sum_of_even_numbers_iterative(n1)
    result1_formula = sum_of_even_numbers_formula(n1)
    result1_rec = sum_of_even_numbers_recursive(n1)
    even_nums1 = get_first_n_even_numbers(n1)
    print(f"n = {n1}")
    print(f"First {n1} even numbers: {even_nums1}")
    print(f"Sum (iterative): {result1_iter}")
    print(f"Sum (formula): {result1_formula}")
    print(f"Sum (recursive): {result1_rec}")
    print(f"Verification: {n1} × ({n1} + 1) = {n1 * (n1 + 1)}")
    
    # Test Case 2 - Sum of first 10 even numbers
    n2 = 10
    result2 = sum_of_even_numbers_formula(n2)
    even_nums2 = get_first_n_even_numbers(n2)
    print(f"\nn = {n2}")
    print(f"First {n2} even numbers: {even_nums2}")
    print(f"Sum: {result2}")
    print(f"Verification: {n2} × ({n2} + 1) = {n2 * (n2 + 1)}")
    
    # Test Case 3 - Sum of first 1 even number
    n3 = 1
    result3 = sum_of_even_numbers_formula(n3)
    print(f"\nn = {n3}")
    print(f"Sum: {result3}")
    
    # Test Case 4 - Sum of first 5 even numbers
    n4 = 5
    result4 = sum_of_even_numbers_formula(n4)
    even_nums4 = get_first_n_even_numbers(n4)
    print(f"\nn = {n4}")
    print(f"First {n4} even numbers: {even_nums4}")
    print(f"Sum: {result4}")
    
    # Test Case 5 - Large n
    n5 = 20
    result5 = sum_of_even_numbers_formula(n5)
    print(f"\nn = {n5}")
    print(f"Sum of first {n5} even numbers: {result5}")
    print(f"Verification: {n5} × ({n5} + 1) = {n5 * (n5 + 1)}")
