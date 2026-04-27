/*
 * LC 299 - Bulls and Cows
 * Difficulty : Medium
 * Topic      : Hashing / Strings
 * Approach   : Pass 1 — count bulls (exact pos match), store leftover
 *              secret digits in map. Pass 2 — count cows using the map.
 * TC: O(n)   SC: O(1) — map holds at most 10 digits
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m;
        int bulls = 0, cows = 0;

        for (int i = 0; i < (int)secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                m[secret[i]]++;
            }
        }

        for (int i = 0; i < (int)secret.size(); i++) {
            if (secret[i] != guess[i]) {
                if (m[guess[i]] > 0) {
                    cows++;
                    m[guess[i]]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
