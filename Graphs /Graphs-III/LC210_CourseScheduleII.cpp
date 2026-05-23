// LC 210 - Course Schedule II
// Topological Sort (DFS-based) + Cycle Detection
// Time: O(V + E) | Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& graph) {
        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < graph.size(); i++) {
            // edge: v <---- u (prereq format: [v, u] means u -> v)
            int u = graph[i][1];
            int v = graph[i][0];

            if (u == src) {
                if (!vis[v]) {
                    if (isCycle(v, vis, recPath, graph)) {
                        return true;
                    }
                } else {
                    if (recPath[v]) {
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& graph) {
        vis[src] = true;

        for (int i = 0; i < graph.size(); i++) {
            // edge: v <---- u
            int u = graph[i][1];
            int v = graph[i][0];

            if (u == src) {
                if (!vis[v]) {
                    topoSort(v, vis, s, graph);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        stack<int> s;
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        vector<int> ans;

        // Step 1: cycle detection — if cycle exists, no valid ordering
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, recPath, prerequisites)) {
                    return ans; // empty
                }
            }
        }

        // Step 2: topo sort on DAG
        vector<bool> vis2(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis2[i]) {
                topoSort(i, vis2, s, prerequisites);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
