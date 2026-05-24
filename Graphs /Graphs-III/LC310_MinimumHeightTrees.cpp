// LC 310 - Minimum Height Trees
// Approach: Leaf peeling (Kahn's-style BFS)
// - Center of tree is always 1 or 2 nodes
// - Iteratively remove leaves until <= 2 nodes remain
// TC: O(n) | SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        queue<int> q;
        vector<int> ans;
        int remaining = n;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            while (sz--) {
                int leaf = q.front();
                q.pop();
                for (int neighbour : adj[leaf]) {
                    degree[neighbour]--;
                    if (degree[neighbour] == 1) {
                        q.push(neighbour);
                    }
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
