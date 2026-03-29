/**
 * ============================================================
 * @file    LC242_ValidAnagram.cpp
 * @brief   LC 242 — Valid Anagram
 * ------------------------------------------------------------
 * Approach : Frequency count with int[26]
 *            Count chars in s, subtract for t, check all zero.
 *            Here: two separate arrays compared at the end.
 * Time  : O(n)   — single pass each string
 * Space : O(1)   — fixed 26-element arrays
 * ============================================================
 */

#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for (int i = 0; i < s.length(); i++)
            a[s[i] - 'a']++;

        int b[26] = {0};
        for (int i = 0; i < t.length(); i++)
            b[t[i] - 'a']++;

        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;

        return true;
    }
};
