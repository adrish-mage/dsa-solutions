/*
 * LC 242 - Valid Anagram
 * Difficulty : Easy
 * Topic      : Hashing / Strings
 * Approach   : Frequency map for s; decrement for t.
 *              If map is empty at end => anagram.
 * TC: O(n)   SC: O(1) — at most 26 chars
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char,int> m; // {char, freq}

        for (char ch : s) {
            m[ch]++;
        }

        for (char ch : t) {
            if (m.count(ch)) {
                m[ch]--;
                if (m[ch] == 0) {
                    m.erase(ch);
                }
            } else {
                return false;
            }
        }

        return m.size() == 0;
    }
};
