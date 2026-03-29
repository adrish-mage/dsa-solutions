/**
 * ============================================================
 * @file    LC125_ValidPalindrome.cpp
 * @brief   LC 125 — Valid Palindrome
 * ------------------------------------------------------------
 * Approach : Two pointers (left, right) skipping non-alphanumeric
 *            characters, comparing lowercased chars inward.
 * Time  : O(n)   — single pass
 * Space : O(1)   — in-place on input string
 * ============================================================
 */

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left]))  left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++; right--;
        }
        return true;
    }
};
