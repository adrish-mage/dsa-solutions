// Problem: Missing Number
// LC 268 | Easy
// Approach: XOR all indices and all elements — matching pairs cancel, missing number remains
// Key trick: a ^ a = 0, so only the missing number survives
// Gotcha: XOR n separately since loop runs 0..n-1
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorEl = 0;
        int xorNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorEl ^= nums[i];
            xorNum ^= i;
        }
        xorNum ^= nums.size();
        return xorEl ^ xorNum;
    }
};
