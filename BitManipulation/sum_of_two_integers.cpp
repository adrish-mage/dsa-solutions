// Problem: Sum of Two Integers
// LC 371 | Medium
// Approach: Recursive XOR + carry simulation without + operator
// Key trick: a ^ b adds without carry, (a & b) << 1 computes carry shifted left
// Time: O(1) | Space: O(1)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getSum(a ^ b, (a & b) << 1);
    }
};
