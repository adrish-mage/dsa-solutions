// LC 207 - Course Schedule
// Approach: Directed graph cycle detection using DFS with 3 states
// vis[] = visited ever, pathVis[] = on current DFS path
// If we hit a node that's on the current path -> cycle -> cannot finish

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int src, vector<vector<int>>& adj,
             vector<bool>& vis,
             vector<bool>& pathVis) {

        vis[src] = true;
        pathVis[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (dfs(v, adj, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[v]) {
                return true;
            }
        }

        pathVis[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return false;
                }
            }
        }

        return true;
    }
};
