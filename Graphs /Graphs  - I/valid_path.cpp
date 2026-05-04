// LC 1971  : Find if Path Exists in Graph
// Difficulty: Easy
// Topic   : Graphs - DFS
// TC      : O(V + E)
// SC      : O(V) — vis array + recursion stack

#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPathHelper(int source, vector<bool>& vis, vector<list<int>>& l, int destination) {
        if (source == destination) return true;

        vis[source] = true;

        for (int v : l[source]) {
            if (!vis[v]) {
                if (validPathHelper(v, vis, l, destination)) return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> l(n);

        for (auto& e : edges) {
            l[e[0]].push_back(e[1]);
            l[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        return validPathHelper(source, vis, l, destination);
    }
};
