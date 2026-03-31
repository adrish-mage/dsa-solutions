// LC 3 · Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: Sliding window with boolean frequency array
// Time: O(n)  |  Space: O(1)
// Key insight: Expand right pointer, shrink left when duplicate appears

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0; 
        bool seen[128] = {false};
        int maxLen = 0;

        for(int right = 0; right < n; right++){
            while (seen[s[right]]){
                seen[s[left]] = false;
                left++;
            }
            seen[s[right]] = true;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};