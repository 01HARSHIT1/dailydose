"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Calculate Power of a Number
# Calculate a raised to the power b (a^b)

def power_iterative(base, exponent):
    """
    Calculate power using iterative approach
    Time Complexity: O(exponent)
    Space Complexity: O(1)
    """
    if exponent < 0:
        return None  # Handle negative exponents separately
    
    result = 1
    for _ in range(exponent):
        result *= base
    return result


def power_recursive(base, exponent):
    """
    Calculate power using recursive approach
    Time Complexity: O(exponent)
    Space Complexity: O(exponent) due to recursion stack
    """
    if exponent < 0:
        return None  # Handle negative exponents separately
    if exponent == 0:
        return 1
    return base * power_recursive(base, exponent - 1)


def power_optimized(base, exponent):
    """
    Calculate power using optimized approach (binary exponentiation)
    Time Complexity: O(log exponent)
    Space Complexity: O(log exponent) due to recursion
    """
    if exponent < 0:
        return None
    
    if exponent == 0:
        return 1
    if exponent == 1:
        return base
    
    if exponent % 2 == 0:
        # If exponent is even: base^exponent = (base^2)^(exponent/2)
        return power_optimized(base * base, exponent // 2)
    else:
        # If exponent is odd: base^exponent = base * base^(exponent-1)
        return base * power_optimized(base * base, (exponent - 1) // 2)


# Problem 2: Find LCM (Least Common Multiple) of Two Numbers
# Find the smallest positive integer that is divisible by both numbers

def find_lcm(a, b):
    """
    Find LCM using formula: LCM(a, b) = (a * b) / GCD(a, b)
    Time Complexity: O(log(min(a, b))) - due to GCD calculation
    Space Complexity: O(1)
    """
    def gcd(x, y):
        """Calculate GCD using Euclidean algorithm"""
        while y != 0:
            x, y = y, x % y
        return abs(x)
    
    if a == 0 or b == 0:
        return 0
    
    return abs(a * b) // gcd(a, b)


def find_lcm_brute_force(a, b):
    """
    Find LCM using brute force approach
    Time Complexity: O(a * b)
    Space Complexity: O(1)
    """
    a, b = abs(a), abs(b)
    if a == 0 or b == 0:
        return 0
    
    max_num = max(a, b)
    while True:
        if max_num % a == 0 and max_num % b == 0:
            return max_num
        max_num += 1


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Calculate Power of a Number")
    print("=" * 60)
    
    # Test Case 1
    base1, exp1 = 2, 5
    pow_iter1 = power_iterative(base1, exp1)
    pow_rec1 = power_recursive(base1, exp1)
    pow_opt1 = power_optimized(base1, exp1)
    print(f"Base: {base1}, Exponent: {exp1}")
    print(f"Result (Iterative): {pow_iter1}")
    print(f"Result (Recursive): {pow_rec1}")
    print(f"Result (Optimized): {pow_opt1}")
    
    # Test Case 2
    base2, exp2 = 3, 4
    pow_iter2 = power_iterative(base2, exp2)
    pow_rec2 = power_recursive(base2, exp2)
    pow_opt2 = power_optimized(base2, exp2)
    print(f"\nBase: {base2}, Exponent: {exp2}")
    print(f"Result (Iterative): {pow_iter2}")
    print(f"Result (Recursive): {pow_rec2}")
    print(f"Result (Optimized): {pow_opt2}")
    
    # Test Case 3 - Power of 0
    base3, exp3 = 5, 0
    pow_iter3 = power_iterative(base3, exp3)
    pow_rec3 = power_recursive(base3, exp3)
    pow_opt3 = power_optimized(base3, exp3)
    print(f"\nBase: {base3}, Exponent: {exp3}")
    print(f"Result (Iterative): {pow_iter3}")
    print(f"Result (Recursive): {pow_rec3}")
    print(f"Result (Optimized): {pow_opt3}")
    
    # Test Case 4 - Base is 0
    base4, exp4 = 0, 5
    pow_iter4 = power_iterative(base4, exp4)
    pow_rec4 = power_recursive(base4, exp4)
    pow_opt4 = power_optimized(base4, exp4)
    print(f"\nBase: {base4}, Exponent: {exp4}")
    print(f"Result (Iterative): {pow_iter4}")
    print(f"Result (Recursive): {pow_rec4}")
    print(f"Result (Optimized): {pow_opt4}")
    
    # Test Case 5 - Large exponent
    base5, exp5 = 2, 10
    pow_iter5 = power_iterative(base5, exp5)
    pow_rec5 = power_recursive(base5, exp5)
    pow_opt5 = power_optimized(base5, exp5)
    print(f"\nBase: {base5}, Exponent: {exp5}")
    print(f"Result (Iterative): {pow_iter5}")
    print(f"Result (Recursive): {pow_rec5}")
    print(f"Result (Optimized): {pow_opt5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find LCM (Least Common Multiple) of Two Numbers")
    print("=" * 60)
    
    # Test Case 1
    a1, b1 = 12, 18
    lcm1 = find_lcm(a1, b1)
    lcm_bf1 = find_lcm_brute_force(a1, b1)
    print(f"Numbers: {a1}, {b1}")
    print(f"LCM (Using GCD formula): {lcm1}")
    print(f"LCM (Brute Force): {lcm_bf1}")
    
    # Test Case 2
    a2, b2 = 15, 25
    lcm2 = find_lcm(a2, b2)
    lcm_bf2 = find_lcm_brute_force(a2, b2)
    print(f"\nNumbers: {a2}, {b2}")
    print(f"LCM (Using GCD formula): {lcm2}")
    print(f"LCM (Brute Force): {lcm_bf2}")
    
    # Test Case 3 - Coprime numbers
    a3, b3 = 7, 13
    lcm3 = find_lcm(a3, b3)
    lcm_bf3 = find_lcm_brute_force(a3, b3)
    print(f"\nNumbers: {a3}, {b3}")
    print(f"LCM (Using GCD formula): {lcm3}")
    print(f"LCM (Brute Force): {lcm_bf3}")
    
    # Test Case 4 - Same numbers
    a4, b4 = 10, 10
    lcm4 = find_lcm(a4, b4)
    lcm_bf4 = find_lcm_brute_force(a4, b4)
    print(f"\nNumbers: {a4}, {b4}")
    print(f"LCM (Using GCD formula): {lcm4}")
    print(f"LCM (Brute Force): {lcm_bf4}")
    
    # Test Case 5 - One number is multiple of other
    a5, b5 = 5, 15
    lcm5 = find_lcm(a5, b5)
    lcm_bf5 = find_lcm_brute_force(a5, b5)
    print(f"\nNumbers: {a5}, {b5}")
    print(f"LCM (Using GCD formula): {lcm5}")
    print(f"LCM (Brute Force): {lcm_bf5}")
    
    # Test Case 6 - Large numbers
    a6, b6 = 48, 60
    lcm6 = find_lcm(a6, b6)
    lcm_bf6 = find_lcm_brute_force(a6, b6)
    print(f"\nNumbers: {a6}, {b6}")
    print(f"LCM (Using GCD formula): {lcm6}")
    print(f"LCM (Brute Force): {lcm_bf6}")
