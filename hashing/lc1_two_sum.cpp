/*
 * LC 1 - Two Sum
 * Difficulty : Easy
 * Topic      : Hashing / Arrays
 * Approach   : Single-pass hashmap — store each element's index;
 *              for every element check if (target - nums[i]) exists.
 * TC: O(n)   SC: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; // {val, idx}

        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
