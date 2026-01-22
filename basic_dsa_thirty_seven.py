"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Check if a Number is Trimorphic
# A Trimorphic number is a number whose cube ends with the number itself
# Example: 4³ = 64 (ends with 4), 5³ = 125 (ends with 5), 25³ = 15625 (ends with 25)

def count_digits(n):
    """
    Count number of digits in a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n == 0:
        return 1
    count = 0
    num = abs(n)
    while num > 0:
        count += 1
        num //= 10
    return count


def is_trimorphic_number(n):
    """
    Check if a number is Trimorphic number
    A Trimorphic number's cube ends with the number itself
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    
    cube = n * n * n
    num_digits = count_digits(n)
    
    # Extract last num_digits from cube
    divisor = 10 ** num_digits
    last_digits = cube % divisor
    
    return last_digits == n


def get_trimorphic_numbers_in_range(start, end):
    """
    Find all Trimorphic numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Trimorphic numbers
    """
    trimorphic_numbers = []
    
    for num in range(start, end + 1):
        if is_trimorphic_number(num):
            trimorphic_numbers.append(num)
    
    return trimorphic_numbers


def get_cube_last_digits(n, num_digits):
    """
    Get the last num_digits of cube of a number
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    cube = n * n * n
    divisor = 10 ** num_digits
    return cube % divisor


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if a Number is Trimorphic")
    print("=" * 60)
    
    # Test Case 1 - Trimorphic number 4
    num1 = 4
    result1 = is_trimorphic_number(num1)
    cube1 = num1 * num1 * num1
    last_digits1 = get_cube_last_digits(num1, count_digits(num1))
    print(f"Number: {num1}")
    print(f"Cube: {cube1}")
    print(f"Last digits of cube: {last_digits1}")
    print(f"Is Trimorphic number: {result1}")
    
    # Test Case 2 - Trimorphic number 5
    num2 = 5
    result2 = is_trimorphic_number(num2)
    cube2 = num2 * num2 * num2
    last_digits2 = get_cube_last_digits(num2, count_digits(num2))
    print(f"\nNumber: {num2}")
    print(f"Cube: {cube2}")
    print(f"Last digits of cube: {last_digits2}")
    print(f"Is Trimorphic number: {result2}")
    
    # Test Case 3 - Trimorphic number 25
    num3 = 25
    result3 = is_trimorphic_number(num3)
    cube3 = num3 * num3 * num3
    last_digits3 = get_cube_last_digits(num3, count_digits(num3))
    print(f"\nNumber: {num3}")
    print(f"Cube: {cube3}")
    print(f"Last digits of cube: {last_digits3}")
    print(f"Is Trimorphic number: {result3}")
    
    # Test Case 4 - Not Trimorphic number
    num4 = 6
    result4 = is_trimorphic_number(num4)
    cube4 = num4 * num4 * num4
    last_digits4 = get_cube_last_digits(num4, count_digits(num4))
    print(f"\nNumber: {num4}")
    print(f"Cube: {cube4}")
    print(f"Last digits of cube: {last_digits4}")
    print(f"Is Trimorphic number: {result4}")
    
    # Test Case 5 - Single digit Trimorphic
    num5 = 1
    result5 = is_trimorphic_number(num5)
    cube5 = num5 * num5 * num5
    print(f"\nNumber: {num5}")
    print(f"Cube: {cube5}")
    print(f"Is Trimorphic number: {result5}")
    
    # Test Case 6 - Find Trimorphic numbers in range
    start = 1
    end = 100
    trimorphic_nums = get_trimorphic_numbers_in_range(start, end)
    print(f"\nTrimorphic numbers in range [{start}, {end}]:")
    print(trimorphic_nums)
    print(f"Count: {len(trimorphic_nums)}")
    
    # Test Case 7 - Trimorphic number 49
    num7 = 49
    result7 = is_trimorphic_number(num7)
    cube7 = num7 * num7 * num7
    last_digits7 = get_cube_last_digits(num7, count_digits(num7))
    print(f"\nNumber: {num7}")
    print(f"Cube: {cube7}")
    print(f"Last digits of cube: {last_digits7}")
    print(f"Is Trimorphic number: {result7}")
