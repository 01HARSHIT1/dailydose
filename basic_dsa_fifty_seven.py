"""
Basic DSA - Count Primes
Return the number of prime numbers strictly less than n.
"""


def count_primes(n):
    """
    Sieve of Eratosthenes.
    Time Complexity: O(n log log n)
    Space Complexity: O(n)
    """
    if n <= 2:
        return 0
    is_prime = [True] * n
    is_prime[0] = is_prime[1] = False
    i = 2
    while i * i < n:
        if is_prime[i]:
            for j in range(i * i, n, i):
                is_prime[j] = False
        i += 1
    return sum(is_prime)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Count Primes")
    print("=" * 60)

    tests = [
        (10, 4),
        (0, 0),
        (1, 0),
        (2, 0),
        (3, 1),
        (100, 25),
    ]

    for n, expected in tests:
        got = count_primes(n)
        print(f"n={n} -> {got} (expected {expected})")
