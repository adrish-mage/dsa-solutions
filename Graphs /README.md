#  Graph III — Topological Sort
##  Approaches
### 1. DFS-based (Post-order stack)
```
Run DFS. Push a node to the stack only AFTER all its descendants finish.
Pop the stack at the end → valid topo order.
```
**Key invariant:** A node enters the stack only once all nodes reachable from it are already in the stack — so it ends up *before* them when popped.
- Time: `O(V + E)`
- Space: `O(V)` stack + recursion
### 2. Kahn's Algorithm (BFS / Indegree)
```
Compute indegree of every node.
Push all nodes with indegree 0 into a queue.
Process queue: for each node, reduce neighbor indegrees; push any that hit 0.
```
**Bonus:** If the total processed nodes `< V`, a cycle exists (Kahn's doubles as cycle detection in directed graphs).
- Time: `O(V + E)`
- Space: `O(V)`
---
##  Files
| File | Description |
|------|-------------|
| `TopoSort_DFS_Kahns.cpp` | Both approaches implemented on adjacency list graph |
| `LC210_CourseScheduleII.cpp` | LeetCode 210 — find course order or return `[]` if cycle |
| `LC310_MinimumHeightTrees.cpp` | LeetCode 310 — find root(s) with minimum height |
| `LC2115_FindAllRecipes.cpp` | LeetCode 2115 — find all makeable recipes using Kahn's + string graph |
---
##  Problems
| # | Problem | Difficulty | Approach | Status |
|---|---------|------------|----------|--------|
| [210](https://leetcode.com/problems/course-schedule-ii/) | Course Schedule II | 🟡 Medium | DFS Topo + Cycle Detection | ✅ |
| [310](https://leetcode.com/problems/minimum-height-trees/) | Minimum Height Trees | 🟡 Medium | BFS Topo-like + degree checking | ✅ |
| [2115](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/) | Find All Possible Recipes | 🟡 Medium | Kahn's on string graph + recipe index map | ✅ |
---
