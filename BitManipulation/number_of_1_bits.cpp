// Problem: Counting Bits
// LC 191 | Easy
// Approach: For each number 0..n, count set bits using right-shift loop
// Key trick: n & 1 checks LSB, n >> 1 shifts right — manual bit counter
// Alternate O(n) approach: dp[i] = dp[i >> 1] + (i & 1)
// Time: O(n log n) | Space: O(n)
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        for (int i=0; i<32; i++){
            
            ans+= n & 1;
            n = n >> 1;
        }
        return ans;
    }
};
