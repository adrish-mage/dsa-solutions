// LC 733   : Flood Fill
// Difficulty: Easy
// Topic   : Graphs - DFS on 2D grid
// TC      : O(m * n) — every cell visited at most once
// SC      : O(m * n) — recursion stack in worst case (entire grid same color)

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int color) {
        if (r < 0 || r >= (int)image.size()) return;
        if (c < 0 || c >= (int)image[0].size()) return;
        if (image[r][c] != oldColor) return;

        image[r][c] = color;

        dfs(image, r + 1, c, oldColor, color);
        dfs(image, r, c + 1, oldColor, color);
        dfs(image, r - 1, c, oldColor, color);
        dfs(image, r, c - 1, oldColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // guard: if already target color, skip — avoids infinite recursion
        if (oldColor != color) {
            dfs(image, sr, sc, oldColor, color);
        }

        return image;
    }
};
