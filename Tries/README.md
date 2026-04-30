<h1 align="center">🌲 Tries</h1>
<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=flat-square&logo=leetcode&logoColor=black"/>
  <img src="https://img.shields.io/badge/Problems-5-22c55e?style=flat-square"/>
</p>

---

## Core Structure

```cpp
class Node {
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;          // used in prefix problems
};
```

| Component | Purpose |
|-----------|---------|
| `children` | Map from char → next node |
| `endOfWord` | Marks where a complete word ends |
| `freq` | How many words pass through this node |
| `root` | Empty node, entry point for all ops |

---

## Problems

| # | Problem | Difficulty | Key Idea |
|---|---------|------------|----------|
| 208 | [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/) | 🟡 Medium | Insert walks + marks `endOfWord`; startsWith skips `endOfWord` check |
| 720 | [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/) | 🟡 Medium | DFS only through nodes where `endOfWord == true` |
| 139 | [Word Break](https://leetcode.com/problems/word-break/) | 🟡 Medium | Split at every index, recurse on the remainder |
| — | Shortest Unique Prefix | 🟡 Medium (Classic) | Stop at first node where `freq == 1` |
| — | Count Unique Substrings | 🟡 Medium (Classic) | Insert all suffixes → count total nodes |

---

## Pattern Cheatsheet

```
endOfWord gating     →  208, 720
Recursive split      →  139
freq per node        →  ShortestUniquePrefix
suffix trie          →  CountUniqueSubstrings
```

---

## Key Invariants

```
insert     →  freq++ on every node along the path
search     →  return endOfWord at last char, false if path breaks
startsWith →  return true if path exists, don't check endOfWord
getPrefix  →  stop when freq == 1 (only one word goes beyond here)
countNodes →  each node = one unique substring (suffix trie trick)
```

---

*Part of my DSA sprint*
