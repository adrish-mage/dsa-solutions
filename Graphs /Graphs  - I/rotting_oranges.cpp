// 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/
// Approach: Multi-source BFS
// Time: O(m*n) | Space: O(m*n)

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q; // {{r,c}, minute}
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int minutes = 0;

        // push all initially rotten oranges
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i, j), 0));
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            pair<int,int> orange = q.front().first;
            int currentMinute = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = orange.first + dr[d];
                int nc = orange.second + dc[d];

                if (nr < 0 || nr >= grid.size()) continue;
                if (nc < 0 || nc >= grid[0].size()) continue;
                if (grid[nr][nc] != 1) continue;

                grid[nr][nc] = 2;
                vis[nr][nc] = true;
                q.push({{nr, nc}, currentMinute + 1});
                minutes = max(minutes, currentMinute + 1);
            }
        }

        // if any fresh orange remains, return -1
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) return -1;

        return minutes;
    }
};
