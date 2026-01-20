"""
Basic DSA Problems - Two Fundamental Questions
"""


# Problem 1: Find Largest of Three Numbers
# Return the largest among a, b, c
def largest_of_three(a, b, c):
    """
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if a >= b and a >= c:
        return a
    if b >= a and b >= c:
        return b
    return c


# Problem 2: Check if a Year is a Leap Year
# Leap year rules:
# - divisible by 400 => leap
# - divisible by 100 => not leap
# - divisible by 4 => leap
def is_leap_year(year):
    """
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    return year % 4 == 0


if __name__ == "__main__":
    print("Problem 1 - Largest of Three Numbers:")
    print(largest_of_three(10, 20, 5))   # 20
    print(largest_of_three(-1, -5, -3))  # -1
    print(largest_of_three(7, 7, 2))     # 7

    print("\nProblem 2 - Leap Year Check:")
    for y in [1900, 2000, 2024, 2023]:
        print(y, "=>", is_leap_year(y))

