<h1 align="center">🔤 Strings</h1>
<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=flat-square&logo=leetcode&logoColor=black"/>
  <img src="https://img.shields.io/badge/Problems-8-22c55e?style=flat-square"/>
</p>

---

##  Core Tricks

| Trick | Expression | What it does |
|-------|------------|--------------|
| Frequency count | `freq[s[i] - 'a']++` | Map char to index 0–25 |
| Two pointers | `left++, right--` | Shrink window from both ends |
| Sliding window | `while(set/count invalid) left++` | Maintain valid substring window |
| Expand around center | `l--, r++` while `s[l]==s[r]` | Find palindromes in O(n²) |
| Anagram key | `sort(str)` | Canonical form for grouping |
| Skip non-alphanum | `isalnum(s[i])` | Ignore punctuation/spaces |
| Case-insensitive cmp | `tolower(s[i])` | Normalize before comparing |

---

##  Problems

| # | Problem | Difficulty | Key Trick |
|---|---------|------------|-----------|
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | 🟡 Medium | Sliding window + set/map |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | 🟡 Medium | Expand around center (odd + even) |
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | 🟢 Easy | Stack — match opening brackets |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | 🟡 Medium | Sort each word as group key |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | 🟢 Easy | Two pointers, skip non-alphanumeric |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | 🟢 Easy | Frequency count with int[26] |
| 387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) | 🟢 Easy | Two-pass frequency count |
| 647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | 🟡 Medium | Expand around center (count all) |

---

##  Pattern Cheatsheet


```
Sliding window → 3
Frequency count → 242, 387
Two pointers → 125
Expand center → 5, 647
Stack → 20
Sorting / hash → 49
```

---

*Part of my DSA sprint*
