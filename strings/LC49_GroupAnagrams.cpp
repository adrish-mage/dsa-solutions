/**
 * ============================================================
 * @file    LC49_GroupAnagrams.cpp
 * @brief   LC 49 — Group Anagrams
 * ------------------------------------------------------------
 * Approach : Sort-index trick (no extra string copies stored)
 *            Build an index array [0..n-1], sort it using each
 *            string's sorted form as the key, then sweep to
 *            collect consecutive equal-key indices into groups.
 * Time  : O(n · k log k)  — n strings, each of length k sorted
 * Space : O(n)             — index array + output
 *
 * Alternative (simpler, slightly more space):
 *   unordered_map<string, vector<string>> where key = sorted word
 * ============================================================
 */

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            string ka = strs[a], kb = strs[b];
            sort(ka.begin(), ka.end());
            sort(kb.begin(), kb.end());
            return ka < kb;
        });

        vector<vector<string>> ans;
        int i = 0;
        while (i < n) {
            vector<string> group;
            string curKey = strs[idx[i]];
            sort(curKey.begin(), curKey.end());

            while (i < n) {
                string k = strs[idx[i]];
                sort(k.begin(), k.end());
                if (k != curKey) break;
                group.push_back(strs[idx[i]]);
                i++;
            }
            ans.push_back(group);
        }
        return ans;
    }
};
