// LC 743 - Network Delay Time
// https://leetcode.com/problems/network-delay-time/
// Approach: Dijkstra's Algorithm (directed weighted graph)
// Time: O((V + E) log V) | Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> l(n + 1);

        // graph construction: u -> {v, wt}
        for (int i = 0; i < (int)times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            l[u].push_back({v, wt});
        }

        // min heap: {dist[v], v}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            // stale entry check: skip if we already found a shorter path
            if (wt > dist[u]) {
                continue;
            }

            for (pair<int,int> neighbor : l[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // answer = max dist across all nodes (signal must reach everyone)
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // some node unreachable
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
