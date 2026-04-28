"""
Basic DSA - Gas Station
There are n gas stations along a circular route, where gas[i] is the amount of gas at station i
and cost[i] is the cost to travel from station i to station i+1.
Return the starting station's index if you can travel around the circuit once, otherwise -1.
If a solution exists, it is guaranteed to be unique.
"""


def can_complete_circuit(gas, cost):
    """
    Greedy:
    - If total gas < total cost => impossible.
    - Otherwise, the answer is the first index after any point where the running tank becomes negative.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    total = 0
    tank = 0
    start = 0
    for i in range(len(gas)):
        diff = gas[i] - cost[i]
        total += diff
        tank += diff
        if tank < 0:
            start = i + 1
            tank = 0
    return start if total >= 0 else -1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Gas Station")
    print("=" * 60)

    print(can_complete_circuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]))  # 3
    print(can_complete_circuit([2, 3, 4], [3, 4, 3]))  # -1
