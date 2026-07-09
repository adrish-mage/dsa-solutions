# Graphs - IV : Dijkstra Variants && MST

Problems applying Dijkstra beyond plain shortest path — modified relaxation logic
and stale-entry handling as the recurring pattern. Also includes a direct
Prim's MST application, since the same min-heap greedy-frontier idea drives
both shortest-path and minimum-spanning-tree problems.

Also includes: `code.cpp` — reference implementations of Dijkstra, Bellman-Ford,
and Prim's Algo built during Phase 7 graph study.

---

## Problems

| # | Problem | Difficulty | Key Idea |
|---|---------|------------|----------|
| LC743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | Medium | Standard Dijkstra on directed graph; answer = max of dist[] |
| LC1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) | Medium | Modified Dijkstra on 2D grid; relax with `max(effort, abs diff)` |
| LC1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) | Medium | Prim's MST; min heap grows frontier by pushing every unvisited node's Manhattan distance |

---

## Core Pattern: Stale Entry Check

Both Dijkstra-based problems use a lazy-deletion min heap. Nodes can be pushed multiple times
as shorter paths are found. Before processing a node, verify it isn't stale:

```cpp
if (wt > dist[u]) continue;   // 1D (LC743)
if (d > dist[r][c]) continue; // 2D grid (LC1631)
```

Without this, you re-relax already-settled nodes and get wrong answers or TLE.

## Core Pattern: Prim's MST Frontier

LC1584 swaps "shortest path from source" for "cheapest way to grow a connected tree."
Same min-heap skeleton as Dijkstra, but the relaxation check is replaced by a
visited-set check — once a node joins the MST, its edge weight is locked in and
its neighbors are pushed regardless of any prior distance:

```cpp
if (!mst[u]) {
    mst[u] = true;
    cost += wt;
    // push edges to all unvisited v, no dist[] comparison needed
}
```

- **`dijkstra()`** — adjacency list with `Edge` struct, `vector<vector<Edge>>`
- **`bellmanFord()`** — V-1 passes over all edges, detects negative cycles on pass V
- **`Graph::primsAlgo()`** — MST via greedy min heap on `list<pair<int,int>>[]`

---

## Complexity

| Problem | Time | Space |
|---------|------|-------|
| LC743 | O((V+E) log V) | O(V+E) |
| LC1631 | O(R·C · log(R·C)) | O(R·C) |
| LC1584 | O(V² log V) | O(V) |
| Dijkstra ref | O((V+E) log V) | O(V+E) |
| Bellman-Ford ref | O(V·E) | O(V) |
| Prim's ref | O(E log V) | O(V) |
