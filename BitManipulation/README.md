<h1 align="center">⚡ Bit Manipulation</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=flat-square&logo=leetcode&logoColor=black"/>
  <img src="https://img.shields.io/badge/Problems-7-22c55e?style=flat-square"/>
  
</p>



---

## 🧠 Core Tricks

| Trick | Expression | What it does |
|-------|-----------|--------------|
| Check bit | `n & (1 << i)` | Is i-th bit set? |
| Set bit | `n \| (1 << i)` | Turn on i-th bit |
| Clear bit | `n & ~(1 << i)` | Turn off i-th bit |
| Toggle bit | `n ^ (1 << i)` | Flip i-th bit |
| Clear lowest set bit | `n & (n - 1)` | Drops the rightmost 1 |
| Isolate lowest set bit | `n & (-n)` | Only the rightmost 1 |
| XOR cancel | `a ^ a = 0` | Same values cancel |
| Power of 2 check | `n & (n-1) == 0` | True if power of 2 |
  


---

## 📂 Problems

| # | Problem | Difficulty | Key Trick |
|---|---------|------------|-----------|
| 136 | [Single Number](https://leetcode.com/problems/single-number/) | 🟢 Easy | XOR cancels duplicates |
| 191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | 🟢 Easy | `n & (n-1)` clears lowest set bit |
| 190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | 🟢 Easy | Shift + OR, 32 iterations |
| 338 | [Counting Bits](https://leetcode.com/problems/counting-bits/) | 🟢 Easy | DP — `dp[i] = dp[i >> 1] + (i & 1)` |
| 268 | [Missing Number](https://leetcode.com/problems/missing-number/) | 🟢 Easy | XOR all indices + values |
| 371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | 🟡 Medium | `a ^ b` for sum, `(a & b) << 1` for carry |
| 287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | 🟡 Medium | Bit count per position |

---

## 💡 Pattern Cheatsheet
```
XOR patterns        →  136, 268
Brian Kernighan     →  191, 338
Bit shifting        →  190, 371
Bit counting        →  287
```

---

*Part of my DSA sprint*
