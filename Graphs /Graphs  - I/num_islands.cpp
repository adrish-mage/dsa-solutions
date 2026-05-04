// LC 200   : Number of Islands
// Difficulty: Medium
// Topic   : Graphs - DFS on 2D grid
// TC      : O(m * n) — every cell visited at most once
// SC      : O(m * n) — recursion stack in worst case (one giant island)

#include <vector>
using namespace std;

class Solution {
public:
    // marks all connected land reachable from (r,c) as visited by flipping to '0'
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= (int)grid.size()) return;
        if (c < 0 || c >= (int)grid[0].size()) return;
        if (grid[r][c] == '0') return;

        grid[r][c] = '0';  // mark visited in-place

        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int r = 0; r < (int)grid.size(); r++) {
            for (int c = 0; c < (int)grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);  // sink the entire island
                }
            }
        }

        return count;
    }
};
