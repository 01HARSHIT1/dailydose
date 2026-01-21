"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Odious Number
# An Odious number is a number that has an odd number of 1s in its binary representation
# Example: 5 in binary is 101 (has 2 ones, which is even, so it's not Odious)
# Example: 4 in binary is 100 (has 1 one, which is odd, so it's Odious)

def count_ones_in_binary(n):
    """
    Count number of 1s in binary representation
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    count = 0
    num = abs(n)
    
    while num > 0:
        if num % 2 == 1:
            count += 1
        num //= 2
    
    return count


def is_odious_number(n):
    """
    Check if a number is Odious number (odd number of 1s in binary)
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
    
    ones_count = count_ones_in_binary(n)
    return ones_count % 2 == 1


def is_odious_number_bitwise(n):
    """
    Check if a number is Odious number using bitwise operations
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
    
    count = 0
    while n > 0:
        count += n & 1  # Check if last bit is 1
        n >>= 1  # Right shift
    
    return count % 2 == 1


def get_odious_numbers_in_range(start, end):
    """
    Find all Odious numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Odious numbers
    """
    odious_numbers = []
    
    for num in range(start, end + 1):
        if is_odious_number(num):
            odious_numbers.append(num)
    
    return odious_numbers


# Problem 2: Calculate Compound Interest
# Compound Interest = Principal × (1 + Rate/100)^Time - Principal
# Amount = Principal × (1 + Rate/100)^Time

def calculate_compound_interest(principal, rate, time):
    """
    Calculate compound interest
    Compound Interest = Principal × (1 + Rate/100)^Time - Principal
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if principal < 0 or rate < 0 or time < 0:
        raise ValueError("Principal, rate, and time must be non-negative")
    
    amount = principal * ((1 + rate / 100) ** time)
    interest = amount - principal
    return interest


def calculate_amount_compound_interest(principal, rate, time):
    """
    Calculate total amount with compound interest
    Amount = Principal × (1 + Rate/100)^Time
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if principal < 0 or rate < 0 or time < 0:
        raise ValueError("Principal, rate, and time must be non-negative")
    
    return principal * ((1 + rate / 100) ** time)


def calculate_compound_interest_compounded_n_times(principal, rate, time, n):
    """
    Calculate compound interest compounded n times per year
    Amount = Principal × (1 + Rate/(100×n))^(n×Time)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if principal < 0 or rate < 0 or time < 0 or n <= 0:
        raise ValueError("Principal, rate, and time must be non-negative, n must be positive")
    
    amount = principal * ((1 + rate / (100 * n)) ** (n * time))
    interest = amount - principal
    return interest, amount


def calculate_principal_from_compound_interest(amount, rate, time):
    """
    Calculate principal from compound interest amount
    Principal = Amount / (1 + Rate/100)^Time
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if amount < 0 or rate < 0 or time < 0:
        raise ValueError("Amount, rate, and time must be non-negative")
    
    if rate == 0:
        return amount
    
    return amount / ((1 + rate / 100) ** time)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Odious Number")
    print("=" * 60)
    
    # Test Case 1 - Odious number 4
    num1 = 4
    result1 = is_odious_number(num1)
    result1_bitwise = is_odious_number_bitwise(num1)
    binary1 = bin(num1)[2:]
    ones1 = count_ones_in_binary(num1)
    print(f"Number: {num1}")
    print(f"Binary: {binary1}")
    print(f"Number of 1s: {ones1}")
    print(f"Is Odious number: {result1}")
    print(f"Is Odious number (bitwise): {result1_bitwise}")
    
    # Test Case 2 - Not Odious number 3
    num2 = 3
    result2 = is_odious_number(num2)
    binary2 = bin(num2)[2:]
    ones2 = count_ones_in_binary(num2)
    print(f"\nNumber: {num2}")
    print(f"Binary: {binary2}")
    print(f"Number of 1s: {ones2}")
    print(f"Is Odious number: {result2}")
    
    # Test Case 3 - Odious number 7
    num3 = 7
    result3 = is_odious_number(num3)
    binary3 = bin(num3)[2:]
    ones3 = count_ones_in_binary(num3)
    print(f"\nNumber: {num3}")
    print(f"Binary: {binary3}")
    print(f"Number of 1s: {ones3}")
    print(f"Is Odious number: {result3}")
    
    # Test Case 4 - Zero
    num4 = 0
    result4 = is_odious_number(num4)
    binary4 = bin(num4)[2:]
    ones4 = count_ones_in_binary(num4)
    print(f"\nNumber: {num4}")
    print(f"Binary: {binary4}")
    print(f"Number of 1s: {ones4}")
    print(f"Is Odious number: {result4}")
    
    # Test Case 5 - Find Odious numbers in range
    start = 1
    end = 20
    odious_nums = get_odious_numbers_in_range(start, end)
    print(f"\nOdious numbers in range [{start}, {end}]:")
    print(odious_nums)
    print(f"Count: {len(odious_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Calculate Compound Interest")
    print("=" * 60)
    
    # Test Case 1 - Basic compound interest
    principal1 = 10000
    rate1 = 5
    time1 = 2
    interest1 = calculate_compound_interest(principal1, rate1, time1)
    amount1 = calculate_amount_compound_interest(principal1, rate1, time1)
    print(f"Principal: ₹{principal1}")
    print(f"Rate: {rate1}% per annum")
    print(f"Time: {time1} years")
    print(f"Compound Interest: ₹{interest1:.2f}")
    print(f"Total Amount: ₹{amount1:.2f}")
    
    # Test Case 2 - Different values
    principal2 = 5000
    rate2 = 7.5
    time2 = 3
    interest2 = calculate_compound_interest(principal2, rate2, time2)
    amount2 = calculate_amount_compound_interest(principal2, rate2, time2)
    print(f"\nPrincipal: ₹{principal2}")
    print(f"Rate: {rate2}% per annum")
    print(f"Time: {time2} years")
    print(f"Compound Interest: ₹{interest2:.2f}")
    print(f"Total Amount: ₹{amount2:.2f}")
    
    # Test Case 3 - Quarterly compounding
    principal3 = 10000
    rate3 = 8
    time3 = 2
    n3 = 4  # Quarterly
    interest3, amount3 = calculate_compound_interest_compounded_n_times(principal3, rate3, time3, n3)
    print(f"\nPrincipal: ₹{principal3}")
    print(f"Rate: {rate3}% per annum")
    print(f"Time: {time3} years")
    print(f"Compounding: {n3} times per year (Quarterly)")
    print(f"Compound Interest: ₹{interest3:.2f}")
    print(f"Total Amount: ₹{amount3:.2f}")
    
    # Test Case 4 - Calculate principal from amount
    amount4 = 11025
    rate4 = 5
    time4 = 2
    principal4 = calculate_principal_from_compound_interest(amount4, rate4, time4)
    print(f"\nAmount: ₹{amount4}")
    print(f"Rate: {rate4}% per annum")
    print(f"Time: {time4} years")
    print(f"Principal: ₹{principal4:.2f}")
    
    # Test Case 5 - Monthly compounding
    principal5 = 10000
    rate5 = 6
    time5 = 1
    n5 = 12  # Monthly
    interest5, amount5 = calculate_compound_interest_compounded_n_times(principal5, rate5, time5, n5)
    print(f"\nPrincipal: ₹{principal5}")
    print(f"Rate: {rate5}% per annum")
    print(f"Time: {time5} year")
    print(f"Compounding: {n5} times per year (Monthly)")
    print(f"Compound Interest: ₹{interest5:.2f}")
    print(f"Total Amount: ₹{amount5:.2f}")
