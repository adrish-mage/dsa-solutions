<h1 align="center">Hashing</h1>
<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=flat-square&logo=leetcode&logoColor=black"/>
  <img src="https://img.shields.io/badge/Problems-7-22c55e?style=flat-square"/>
</p>

---

## 🧠 Core Tricks

| Trick | Expression | What it does |
|-------|-----------|--------------|
| Frequency map | `m[x]++` | Count occurrences of x |
| Existence check | `m.count(x)` | O(1) lookup |
| Prefix sum + map | `m[sum - k]` | Count subarrays with sum k |
| Earliest index | `if (!m.count(sum)) m[sum] = i` | Maximise subarray length |
| Set for uniqueness | `unordered_set<int> s` | Dedup in O(n) |
| Complement lookup | `m.count(target - x)` | Two Sum pattern |
| Seed map | `m[0] = 1` | Handle subarrays starting at index 0 |

---

## 📂 Problems

| # | Problem | Difficulty | Key Trick |
|---|---------|------------|-----------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Complement lookup — `target - nums[i]` |
| 229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | 🟡 Medium | Freq map, print if freq > n/3 |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | 🟢 Easy | Freq map — increment for s, decrement for t |
| 299 | [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/) | 🟡 Medium | Two-pass — bulls first, then cows from leftover map |
| 325 | [Max Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | 🟡 Medium ⭐ | Prefix sum + earliest index map |
| 560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | 🟡 Medium | Prefix sum — count of `(sum - k)` in map |
| 1636 | [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/) | 🟢 Easy | Freq map + custom comparator |

*⭐ Premium problem*

---

## 💡 Pattern Cheatsheet

```
Complement lookup   →  1
Frequency map       →  229, 242, 1636
Two-pass map        →  299
Prefix sum + map    →  325, 560
```

---

*Part of my DSA sprint*
