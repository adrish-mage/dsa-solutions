/**
 * ============================================================
 * @file    LC20_ValidParentheses.cpp
 * @brief   LC 20 — Valid Parentheses
 * ------------------------------------------------------------
 * Approach : Stack
 *            Push opening brackets; on closing bracket check
 *            if stack top is the matching opener — pop or fail.
 *            Valid iff stack is empty at the end.
 * Time  : O(n)   — single pass
 * Space : O(n)   — stack can hold up to n/2 openers
 * ============================================================
 */

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if (curr == '(' || curr == '{' || curr == '[') {
                st.push(curr);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((top == '(' && curr == ')') ||
                    (top == '{' && curr == '}') ||
                    (top == '[' && curr == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
