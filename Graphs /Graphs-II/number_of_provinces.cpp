// LC 547 - Number of Provinces
// Approach: Convert adjacency matrix to adjacency list, DFS to count disconnected components

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src, vector<bool>& vis, vector<vector<int>>& l) {
        vis[src] = true;
        for (int v : l[src]) {
            if (!vis[v]) {
                dfs(v, vis, l);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;

        vector<vector<int>> l(n);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1) {
                    l[i].push_back(j);
                    l[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, l);
                count++;
            }
        }

        return count;
    }
};
