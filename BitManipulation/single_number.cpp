// Problem: Single Number
// LC 136 | Easy
// Approach: XOR all elements — duplicates cancel out, unique number remains
// Key trick: a ^ a = 0, a ^ 0 = a
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }
};
