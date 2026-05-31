// LC 1631 - Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/
// Approach: Modified Dijkstra — dist[r][c] = min possible max-effort to reach (r,c)
//           Relax with max(currentEffort, |heights[nr][nc] - heights[r][c]|)
// Time: O(rows * cols * log(rows * cols)) | Space: O(rows * cols)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        const int dr[] = {0, 1, 0, -1};
        const int dc[] = {1, 0, -1, 0};

        // min heap: {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int d = pq.top().first;
            pair<int,int> currIdx = pq.top().second;
            pq.pop();

            int r = currIdx.first;
            int c = currIdx.second;

            // stale entry check
            if (d > dist[r][c]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    // effort to step into neighbor = max of current path effort
                    // and the absolute height diff at this edge
                    int newDist = max(d, abs(heights[nr][nc] - heights[r][c]));

                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};
