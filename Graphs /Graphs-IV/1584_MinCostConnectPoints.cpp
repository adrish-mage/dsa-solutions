// LeetCode 1584. Min Cost to Connect All Points
// Approach: Prim's Algorithm (MST) using a min-heap
// Time: O(V^2 log V) due to pushing all edges per node (can be optimized to O(V^2))
// Space: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        int src = 0;
        vector<bool> mst(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap (wt,u)
        pq.push(make_pair(0, src));
        int cost = 0;

        while (!pq.empty()) {
            pair<int,int> curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int u = curr.second;

            if (!mst[u]) {
                mst[u] = true;
                cost += wt;

                for (int v = 0; v < V; v++) {
                    if (u != v) {
                        int dist = abs(points[v][0] - points[u][0]) + abs(points[v][1] - points[u][1]);
                        pq.push(make_pair(dist, v));
                    }
                }
            }
        }
        return cost;
    }
};

#ifdef LOCAL_TEST
int main() {
    Solution sol;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << sol.minCostConnectPoints(points) << endl; // Expected: 20
    return 0;
}
#endif
