# Graphs

Graph traversal fundamentals and classic grid/connectivity problems solved using BFS and DFS.

---

## Concepts Covered

**Graph representation** — adjacency list using `list<int>[]`, bidirectional edge insertion.

**BFS** — level-order traversal using a queue. Visit immediate neighbours before going deeper. `O(V + E)`.

**DFS** — depth-first traversal using recursion. Keep going to first unvisited neighbour before backtracking. `O(V + E)`.

**Grid as graph** — 2D grids map naturally to graphs where each cell is a node and 4-directional neighbours are edges. No explicit adjacency list needed; recurse directly with `(r, c)` coordinates.

**In-place visited marking** — for grid problems, flip the cell value instead of maintaining a separate `vis[]` array. Cleaner and saves space.

---

## Problems

| File | Problem | Platform | Difficulty | Approach |
|---|---|---|---|---|
| `graph-basics/graph_basics.cpp`  | Graph BFS & DFS | — | Concept | Adjacency list + queue BFS + recursive DFS |
| `valid-path/valid_path.cpp`  | Find if Path Exists in Graph | [LC 1971](https://leetcode.com/problems/find-if-path-exists-in-a-graph/) | Easy | DFS with early return on destination hit |
| `flood-fill/flood_fill.cpp`  | Flood Fill | [LC 733](https://leetcode.com/problems/flood-fill/) | Easy | DFS on 2D grid, old-color guard prevents infinite loop |
| `number-of-islands/num_islands.cpp`   | Number of Islands | [LC 200](https://leetcode.com/problems/number-of-islands/) | Medium | DFS sinks each island in-place, count triggers |
| `rotting-oranges/rotting_oranges.cpp` | Rotting Oranges | [LC 994](https://leetcode.com/problems/rotting-oranges/) | Medium | BFS on 2D grid with level wise counting|


## Notes

- All solutions use `O(V + E)` time — every node and edge is visited at most once.
- In Grid problems matrix is treated as an implicit graph; bounds check replaces the adjacency list lookup.
  
// more problems incoming :)
