Here’s your cleaned and modified version with only the requested LeetCode problems (94, 102, 104, 226, 543) and everything aligned properly:

---

<h1 align="center">🌳 Binary Trees & BST</h1>
<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=flat-square&logo=leetcode&logoColor=black"/>
  <img src="https://img.shields.io/badge/Problems-5-22c55e?style=flat-square"/>
</p>

---

##  Core Concepts

| Concept                   | What it means                            |
| ------------------------- | ---------------------------------------- |
| Inorder (L → Root → R)    | Gives sorted output for a BST            |
| Level Order (BFS)         | Traverse tree level by level using queue |
| Post-order (L → R → Root) | Process children before parent           |
| Height of Tree            | `max(left, right) + 1`                   |
| Diameter                  | Longest path between any two nodes       |
| Tree Transformation       | Modify structure (e.g., invert tree)     |

---

##  Problems

| #   | Problem                                                                                               | Difficulty | Key Idea                        |
| --- | ----------------------------------------------------------------------------------------------------- | ---------- | ------------------------------- |
| 94  | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)         | 🟢 Easy    | Recursive L → Root → R          |
| 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium  | BFS using queue                 |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)           | 🟢 Easy    | Height via recursion            |
| 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)                               | 🟢 Easy    | Swap left & right (post-order)  |
| 543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)                     | 🟡 Medium  | Track longest path using height |

---

##  Pattern Cheatsheet

```
Inorder traversal       →  94
Level Order (BFS)       →  102
Height / Depth          →  104
Post-order + swap       →  226
Diameter (height-based) →  543
```


| Concept practiced          | Related LC problem |
| -------------------------- | ------------------ |
| `inOrder()` traversal      | 94                 |
| Level order (queue BFS)    | 102                |
| `height()` recursion       | 104                |
| Tree transformation (swap) | 226                |
| Diameter via height        | 543                |

---
more codes incoming...
*Part of my DSA sprint*
