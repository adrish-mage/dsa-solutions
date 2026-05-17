# Graphs

Complete graph problem set across 5 parts — from traversal fundamentals to advanced algorithms. Solved in C++ using adjacency list representation.

---

## Structure

```
Graphs/
├── Graphs - I /       BFS, DFS, grid problems, connectivity
├── Graphs - II /      Cycle detection, bipartite, all paths, component count
├── Graphs - III /     Topological sort, shortest paths (BFS/Dijkstra)
├── Graphs - IV /      MST (Prim's, Kruskal's), DSU
└── Graphs - V /       Advanced — Bridges, Articulation points, SCC
```

---

## Graphs - I — Traversal Fundamentals

**Concepts:** Graph representation (adjacency list, matrix, edge list), BFS, DFS, implicit graphs, grid traversal, connectivity.

| File | Problem | Platform | Difficulty | Approach |
|------|---------|----------|------------|----------|
| `graph_basics.cpp` | Graph BFS & DFS | — | Concept | Adjacency list + queue BFS + recursive DFS |
| `valid_path.cpp` | Find if Path Exists in a Graph | [LC 1971](https://leetcode.com/problems/find-if-path-exists-in-a-graph/) | Easy | DFS with early return on destination hit |
| `flood_fill.cpp` | Flood Fill | [LC 733](https://leetcode.com/problems/flood-fill/) | Easy | DFS on 2D grid, old-color guard prevents infinite loop |
| `num_islands.cpp` | Number of Islands | [LC 200](https://leetcode.com/problems/number-of-islands/) | Medium | DFS sinks each island in-place, count triggers |
| `rotting_oranges.cpp` | Rotting Oranges | [LC 994](https://leetcode.com/problems/rotting-oranges/) | Medium | BFS on 2D grid with level-wise counting |

---

## Graphs - II — Cycle Detection & Classic Problems

**Concepts:** Disconnected component count, undirected cycle detection (parent tracking), directed cycle detection (3-state DFS), bipartite check (BFS 2-coloring), all paths via backtracking.

| File | Problem | Platform | Difficulty | Approach |
|------|---------|----------|------------|----------|
| `graph_basics.cpp` | Undirected/Directed Cycle, Bipartite, All Paths | — | Concept | Class-based graph with 4 core algorithms |
| `number_of_provinces.cpp` | Number of Provinces | [LC 547](https://leetcode.com/problems/number-of-provinces/) | Medium | Matrix → adjacency list, DFS component count |
| `course_schedule.cpp` | Course Schedule | [LC 207](https://leetcode.com/problems/course-schedule/) | Medium | Directed DFS, 3-state cycle detection (vis + recPath) |

---

## Graphs - III — Topological Sort & Shortest Paths

*Incoming*

---

## Graphs - IV — MST & DSU

*Incoming*

---

## Graphs - V — Advanced

*Incoming*

---

## Key Patterns
[ covered till now ]

**BFS** — level-order, use for shortest path in unweighted graphs. Queue + visited array. O(V + E).

**DFS** — recursive, use for cycle detection, path finding, component marking. O(V + E).

**Grid as graph** — each cell is a node, 4-directional neighbours are edges. No explicit adjacency list needed; recurse directly with `(r, c)` coordinates.

**Directed vs undirected cycle detection** — undirected needs parent tracking; directed needs a separate recursion-path array (`recPath[]`) that resets on backtrack.

**Bipartite** — BFS 2-coloring. `color[]` initialized to `-1`. If any two adjacent nodes share a color, not bipartite.

**Component count** — always loop over all nodes in the caller. Each fresh DFS/BFS start from an unvisited node = one new component.  
