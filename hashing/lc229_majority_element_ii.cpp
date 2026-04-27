/*
 * LC 229 - Majority Element II
 * Difficulty : Medium
 * Topic      : Hashing
 * Approach   : Build frequency map; print elements with freq > n/3.
 *              At most 2 such elements can exist.
 * TC: O(n)   SC: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m; // {val, freq}
        vector<int> ans;

        for (int num : nums) {
            m[num]++;
        }

        for (pair<int,int> val : m) {
            if (val.second > (int)nums.size() / 3) {
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};
