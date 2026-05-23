// Topological Sort — DFS-based (Post-order stack)
// Also includes Kahn's Algorithm (BFS / Indegree method)
// Graph represented as adjacency list
// Time: O(V + E) | Space: O(V)

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> l; // adjacency list

public:
    Graph(int v) : V(v), l(v) {}

    void addEdge(int u, int v) {
        l[u].push_back(v); // directed: u -> v
    }

    // ─── DFS-based Topo Sort ────────────────────────────────────────────────

    void topoHelper(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                topoHelper(v, vis, s);
            }
        }
        s.push(src); // push AFTER all descendants processed (post-order)
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoHelper(i, vis, s);
            }
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    // ─── Kahn's Algorithm (BFS / Indegree) ──────────────────────────────────

    void calcIndegree(vector<int> &indeg) {
        for (int i = 0; i < V; i++) {
            for (int v : l[i]) {
                indeg[v]++;
            }
        }
    }

    void topoSort2() {
        vector<int> indeg(V, 0);
        calcIndegree(indeg);

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i); // all nodes with no incoming edges are starting points
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int v : l[curr]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Example: 6 nodes, standard topo sort demo
    // 5 -> 0, 5 -> 2, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "DFS Topo Sort:   ";
    g.topoSort();

    cout << "Kahn's Algorithm: ";
    g.topoSort2();

    return 0;
}
