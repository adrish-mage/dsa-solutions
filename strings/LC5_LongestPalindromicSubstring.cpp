/**
 * ============================================================
 * @file    LC5_LongestPalindromicSubstring.cpp
 * @brief   LC 5 — Longest Palindromic Substring
 * ------------------------------------------------------------
 * Approach : Expand Around Center
 *            For each index i, expand outward for both:
 *              - odd-length  palindromes  (center = i)
 *              - even-length palindromes  (center = i, i+1)
 *            Track best (start, maxLen) seen so far.
 * Time  : O(n²)  — n centers × O(n) expansion each
 * Space : O(1)   — only indices stored
 * ============================================================
 */

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // odd-length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) { maxLen = r - l + 1; start = l; }
                l--; r++;
            }
            // even-length
            l = i; r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) { maxLen = r - l + 1; start = l; }
                l--; r++;
            }
        }
        return s.substr(start, maxLen);
    }
};
