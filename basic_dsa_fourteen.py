"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Find Largest of Three Numbers
# Find the largest among three numbers

def find_largest_three(a, b, c):
    """
    Find largest of three numbers using if-else
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if a >= b and a >= c:
        return a
    elif b >= a and b >= c:
        return b
    else:
        return c


def find_largest_three_max(a, b, c):
    """
    Find largest of three numbers using built-in max function
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return max(a, b, c)


def find_largest_three_nested(a, b, c):
    """
    Find largest of three numbers using nested ternary
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return a if (a >= b and a >= c) else (b if b >= c else c)


# Problem 2: Check if a Year is a Leap Year
# Determine whether a given year is a leap year

def is_leap_year(year):
    """
    Check if a year is a leap year
    Leap year rules:
    - Divisible by 4
    - But not divisible by 100 (unless divisible by 400)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if year % 400 == 0:
        return True
    elif year % 100 == 0:
        return False
    elif year % 4 == 0:
        return True
    else:
        return False


def is_leap_year_compact(year):
    """
    Check if a year is a leap year (compact version)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Find Largest of Three Numbers")
    print("=" * 60)
    
    # Test Case 1
    a1, b1, c1 = 10, 20, 15
    largest1 = find_largest_three(a1, b1, c1)
    largest1b = find_largest_three_max(a1, b1, c1)
    largest1c = find_largest_three_nested(a1, b1, c1)
    print(f"Numbers: {a1}, {b1}, {c1}")
    print(f"Largest (If-else): {largest1}")
    print(f"Largest (Max function): {largest1b}")
    print(f"Largest (Nested ternary): {largest1c}")
    
    # Test Case 2 - All same
    a2, b2, c2 = 5, 5, 5
    largest2 = find_largest_three(a2, b2, c2)
    print(f"\nNumbers: {a2}, {b2}, {c2}")
    print(f"Largest: {largest2}")
    
    # Test Case 3 - First is largest
    a3, b3, c3 = 30, 10, 20
    largest3 = find_largest_three(a3, b3, c3)
    print(f"\nNumbers: {a3}, {b3}, {c3}")
    print(f"Largest: {largest3}")
    
    # Test Case 4 - Second is largest
    a4, b4, c4 = 10, 30, 20
    largest4 = find_largest_three(a4, b4, c4)
    print(f"\nNumbers: {a4}, {b4}, {c4}")
    print(f"Largest: {largest4}")
    
    # Test Case 5 - Negative numbers
    a5, b5, c5 = -5, -10, -3
    largest5 = find_largest_three(a5, b5, c5)
    print(f"\nNumbers: {a5}, {b5}, {c5}")
    print(f"Largest: {largest5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Year is a Leap Year")
    print("=" * 60)
    
    # Test Case 1 - Regular leap year
    year1 = 2020
    result1 = is_leap_year(year1)
    result1b = is_leap_year_compact(year1)
    print(f"Year: {year1}")
    print(f"Is Leap Year (Method 1): {result1}")
    print(f"Is Leap Year (Compact): {result1b}")
    
    # Test Case 2 - Not a leap year
    year2 = 2021
    result2 = is_leap_year(year2)
    result2b = is_leap_year_compact(year2)
    print(f"\nYear: {year2}")
    print(f"Is Leap Year (Method 1): {result2}")
    print(f"Is Leap Year (Compact): {result2b}")
    
    # Test Case 3 - Century year (not leap)
    year3 = 1900
    result3 = is_leap_year(year3)
    result3b = is_leap_year_compact(year3)
    print(f"\nYear: {year3}")
    print(f"Is Leap Year (Method 1): {result3}")
    print(f"Is Leap Year (Compact): {result3b}")
    
    # Test Case 4 - Century year (leap - divisible by 400)
    year4 = 2000
    result4 = is_leap_year(year4)
    result4b = is_leap_year_compact(year4)
    print(f"\nYear: {year4}")
    print(f"Is Leap Year (Method 1): {result4}")
    print(f"Is Leap Year (Compact): {result4b}")
    
    # Test Case 5 - Another leap year
    year5 = 2024
    result5 = is_leap_year(year5)
    result5b = is_leap_year_compact(year5)
    print(f"\nYear: {year5}")
    print(f"Is Leap Year (Method 1): {result5}")
    print(f"Is Leap Year (Compact): {result5b}")
    
    # Test Case 6 - Non-leap century
    year6 = 2100
    result6 = is_leap_year(year6)
    result6b = is_leap_year_compact(year6)
    print(f"\nYear: {year6}")
    print(f"Is Leap Year (Method 1): {result6}")
    print(f"Is Leap Year (Compact): {result6b}")
