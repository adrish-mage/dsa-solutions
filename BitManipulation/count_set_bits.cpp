// Problem: Counting Bits
// LC 338 | Easy
// Approach: For each number 0..n, count set bits using right-shift loop
// Key trick: n & 1 checks LSB, n >> 1 shifts right — manual bit counter
// Alternate O(n) approach: dp[i] = dp[i >> 1] + (i & 1)
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            ans[i] = countSetBits(i);
        }
        return ans;
    }
};
