// LC 647 · Palindromic Substrings
// Link: https://leetcode.com/problems/palindromic-substrings/
// Approach: Expand around center (odd + even)
// Time: O(n^2)  |  Space: O(1)
// Key insight: Every character (and gap) can be a palindrome center

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++){
            // Odd length palindromes
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                count++;
                left--;
                right++;
            }

            // Even length palindromes
            left = i, right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};