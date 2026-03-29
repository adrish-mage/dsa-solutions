/**
 * ============================================================
 * @file    LC387_FirstUniqueCharacter.cpp
 * @brief   LC 387 — First Unique Character in a String
 * ------------------------------------------------------------
 * Approach : Two-pass frequency count
 *            Pass 1 — build freq[26] from the whole string.
 *            Pass 2 — return index of first char with freq == 1.
 * Time  : O(n)   — two linear passes
 * Space : O(1)   — fixed 26-element frequency vector
 * ============================================================
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;

        for (int i = 0; i < n; i++)
            if (freq[s[i] - 'a'] == 1) return i;

        return -1;
    }
};
