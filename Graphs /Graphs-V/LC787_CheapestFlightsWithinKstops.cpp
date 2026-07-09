// LeetCode 787. Cheapest Flights Within K Stops
// Approach: BFS (Bellman-Ford style relaxation), tracking stops per path
// Time: O(V * E) worst case
// Space: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Info {
    public:
        int u;
        int cost;
        int stops; // src to u

        Info(int u, int cost, int stops) {
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        q.push(Info(src, 0, -1));

        while (!q.empty()) {
            Info curr = q.front();
            q.pop();

            for (int i = 0; i < flights.size(); i++) {
                if (flights[i][0] == curr.u) {
                    int v = flights[i][1];
                    int wt = flights[i][2];
                    if (dist[v] > curr.cost + wt && curr.stops + 1 <= k) {
                        dist[v] = curr.cost + wt;
                        q.push(Info(v, dist[v], curr.stops + 1));
                    }
                }
            }
        }
        if (dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};

#ifdef LOCAL_TEST
int main() {
    Solution sol;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << sol.findCheapestPrice(3, flights, 0, 2, 1) << endl; // Expected: 200
    return 0;
}
#endif
