/*
 * LC 325 - Maximum Size Subarray Sum Equals k  [Premium]
 * Difficulty : Medium
 * Topic      : Hashing / Prefix Sum
 * Approach   : Prefix sum + hashmap {sum -> earliest index}.
 *              If (sum - k) seen before, subarray length = j - m[sum-k].
 *              Only store index the FIRST time a sum is seen (earliest = longest).
 * TC: O(n)   SC: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> m; // {prefix_sum, earliest_idx}
        int sum = 0;
        int ans = 0;

        for (int j = 0; j < (int)nums.size(); j++) {
            sum += nums[j];

            if (sum == k) {
                ans = j + 1;
            }

            if (m.count(sum - k)) {
                int currLen = j - m[sum - k];
                ans = max(ans, currLen);
            }

            if (!m.count(sum)) {  // only store first occurrence
                m[sum] = j;
            }
        }
        return ans;
    }
};
