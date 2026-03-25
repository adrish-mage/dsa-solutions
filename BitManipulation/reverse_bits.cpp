// Problem: Reverse Bits
// LC 190 | Easy
// Approach: Grab LSB of n one by one, push into result from left to right
// Key trick: result << 1 makes room, | (n & 1) inserts the bit, n >>= 1 moves to next
// Time: O(1) — always 32 iterations | Space: O(1)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};
