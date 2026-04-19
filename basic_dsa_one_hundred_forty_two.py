"""
Basic DSA - Replace Elements with Greatest Element on Right Side
Replace every element with the greatest value among elements to its right;
replace the last element with -1.
"""


def replace_elements(arr):
    """
    Right-to-left scan; carry running max of seen values (original values).
    Time Complexity: O(n)
    Space Complexity: O(1) extra
    """
    mx = -1
    for i in range(len(arr) - 1, -1, -1):
        arr[i], mx = mx, max(mx, arr[i])
    return arr


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Replace Elements with Greatest on Right")
    print("=" * 60)

    print(replace_elements([17, 18, 5, 4, 6, 1].copy()))
    print(replace_elements([400].copy()))
