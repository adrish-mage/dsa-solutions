# Graphs - V : Stop-Constrained Shortest Paths

Problems where the shortest path is bounded by an extra constraint (max stops,
max edges) on top of minimum cost. Plain Dijkstra breaks here —> its greedy
"always expand the cheapest known node" order can permanently lock in a path
that's cheap but uses too many stops, before a valid k-stop path is ever
explored. These need Bellman-Ford-style relaxation instead, where every path
is tracked with its own stop count and relaxed independently.

---

## Problems

| # | Problem | Difficulty | Key Idea |
|---|---------|------------|----------|
| LC787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Medium | BFS-driven relaxation; each queued state carries `(node, cost, stops)`, only relaxed while `stops + 1 <= k` |

---

## Core Pattern: Relax by Stops, Not Just Cost

Dijkstra's stale-entry check (`if (wt > dist[u]) continue`) assumes the first
time you settle a node with minimum cost, you're done with it. Here that's
false —> a costlier path with fewer stops remaining might still be the only
way to legally reach the destination within k. So the relaxation condition
adds a stops guard alongside the cost comparison:

```cpp
if (dist[v] > curr.cost + wt && curr.stops + 1 <= k) {
    dist[v] = curr.cost + wt;
    q.push(Info(v, dist[v], curr.stops + 1));
}
```

This is structurally Bellman-Ford (relax edges repeatedly, no greedy visited
set) rather than Dijkstra, run breadth-first and capped at k+1 edges deep.

**Known limitation of the BFS version:** because there's no per-node
"already expanded at this stop count" dedup, adversarial graphs can re-queue
the same node many times before costs stabilize, blowing up the queue size.
The Bellman-Ford array form (`k+1` full passes over the edge list, relaxing
into a fresh `dist` array each pass) avoids this and is the version to reach
for if runtime becomes an issue.

---

## Complexity

| Problem | Time | Space |
|---------|------|-------|
| LC787 (BFS relaxation) | O(V · E) worst case | O(V) |
| LC787 (Bellman-Ford array form) | O(k · E) | O(V) |
