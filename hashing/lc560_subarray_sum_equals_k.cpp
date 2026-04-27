/*
 * LC 560 - Subarray Sum Equals K
 * Difficulty : Medium
 * Topic      : Hashing / Prefix Sum
 * Approach   : Prefix sum + hashmap. For each index j, if (sum - K)
 *              exists in map, those many subarrays ending at j have sum K.
 *              Seed map with {0,1} to handle subarrays starting at index 0.
 * TC: O(n)   SC: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m; // {prefix_sum, count}
        m[0] = 1;
        int sum = 0;
        int ans = 0;

        for (int j = 0; j < (int)nums.size(); j++) {
            sum += nums[j];

            if (m.count(sum - k)) {
                ans += m[sum - k];   // bug fix: was m[sum], should be m[sum-k]
            }

            m[sum]++;
        }
        return ans;
    }
};
