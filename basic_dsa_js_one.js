/**
 * Basic DSA Problems (JavaScript) - Two Sum
 * Find two indices such that nums[i] + nums[j] = target
 */

/**
 * One pass: store value -> index in map; for each num check if (target - num) exists.
 * Time O(n), Space O(n)
 */
function twoSum(nums, target) {
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    const need = target - nums[i];
    if (map.has(need)) return [map.get(need), i];
    map.set(nums[i], i);
  }
  return [];
}

// --- run ---
console.log("============================================================");
console.log("Problem: Two Sum (JavaScript)");
console.log("============================================================");

console.log("twoSum([2, 7, 11, 15], 9) ->", twoSum([2, 7, 11, 15], 9));
console.log("twoSum([3, 2, 4], 6) ->", twoSum([3, 2, 4], 6));
