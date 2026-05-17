# Graphs — II

Directed graph problems, disconnected component detection, cycle detection, bipartite checking, and path enumeration. Builds on Graphs-I traversal fundamentals.

## Concepts Covered

**Disconnected components** — Loop over all nodes; start a fresh DFS from every unvisited node. Each fresh start = one new component. Count increments in the caller, not inside DFS.

**Undirected cycle detection** — Track parent node to avoid treating the edge we came from as a back edge. If we reach a visited node that isn't the parent, it's a cycle.

**Directed cycle detection** — Two visited arrays needed: `vis[]` tracks if a node was ever visited; `recPath[]` tracks if it's on the *current* DFS call stack. A back edge (reaching a `recPath` node) confirms a cycle. Reset `recPath[src] = false` on backtrack.

**Why undirected ≠ directed cycle detection** — In undirected graphs, revisiting the parent isn't a cycle. In directed graphs, direction matters — two paths reaching the same node isn't a cycle unless one loops back.

**Bipartite check (BFS 2-coloring)** — Assign alternating colors (0/1) using BFS. If two adjacent nodes end up the same color, the graph is not bipartite. Use `color[]` initialized to `-1` instead of a `vis[]` array.

**All paths (DFS backtracking)** — Unmark `vis[src] = false` after exploring all neighbors so other paths can reuse the node. Build path string as you go; trim it on backtrack.

## Problems

| File | Problem | Platform | Difficulty | Approach |
|------|---------|----------|------------|----------|
| `graph_basics.cpp` | Undirected/Directed Cycle, Bipartite, All Paths | — | Concept | Class-based graph with 4 core algorithms |
| `number_of_provinces.cpp` | Number of Provinces | [LC 547](https://leetcode.com/problems/number-of-provinces/) | Medium | Matrix → adjacency list conversion, DFS component count |
| `course_schedule.cpp` | Course Schedule | [LC 207](https://leetcode.com/problems/course-schedule/) | Medium | Directed DFS, 3-state cycle detection (vis + recPath) |

## Notes

- Matrix input doesn't mean matrix traversal — always convert to adjacency list first for clean DFS.
- `recPath[]` must be reset to `false` after a node's DFS completes (backtracking). Forgetting this causes false cycle positives.
- `isConnected[i][i] == 1` in LC 547 (self-loops) — these don't affect component count since the node marks itself visited immediately.
- For multi-digit nodes in path printing, trim by `to_string(src).size()`, not just 1 character.

// more problems incoming :)
