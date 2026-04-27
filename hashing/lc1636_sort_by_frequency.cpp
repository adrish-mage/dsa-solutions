/*
 * LC 1636 - Sort Array by Increasing Frequency
 * Difficulty : Easy
 * Topic      : Hashing / Sorting
 * Approach   : Build frequency map; custom sort — ascending freq,
 *              tie-break by descending value.
 * TC: O(n log n)   SC: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m; // {val, freq}

        for (int num : nums) {
            m[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (m[a] == m[b]) {
                return a > b;       // tie-break: larger value first
            } else {
                return m[a] < m[b]; // ascending frequency
            }
        });

        return nums;
    }
};
