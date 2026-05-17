// Graph Basics — II
// Covers: Undirected cycle detection, Directed cycle detection,
//         Bipartite check (BFS), All Paths (DFS backtracking)

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (isUndir) {
            l[v].push_back(u);
        }
    }

    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << ": ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // --- Undirected Cycle Detection ---
    // Track parent to avoid treating the edge we came from as a back edge
    bool undirCycleHelper(int src, vector<bool>& vis, int par) {
        vis[src] = true;
        for (int v : l[src]) {
            if (!vis[v]) {
                if (undirCycleHelper(v, vis, src)) {
                    return true;
                }
            } else {
                if (v != par) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, vis, -1);
    }

    // --- Directed Cycle Detection ---
    // vis[] = ever visited; recPath[] = on current DFS stack
    // Back edge = reaching a node still on the current path
    bool dirCycleHelper(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false; // backtrack
        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dirCycleHelper(i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }

    // --- Bipartite Check (BFS 2-coloring) ---
    // Assign alternating colors; if two adjacent nodes share a color -> not bipartite
    bool isBipartite(int src) {
        vector<int> color(V, -1);
        queue<int> q;

        q.push(src);
        color[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : l[u]) {
                if (color[v] == -1) {
                    color[v] = !color[u];
                    q.push(v);
                } else {
                    if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // --- All Paths (DFS Backtracking) ---
    // Unmark visited on backtrack so other paths can reuse nodes
    void pathHelper(int src, int dest, vector<bool>& vis, string& path) {
        if (src == dest) {
            cout << path << dest << endl;
            return;
        }
        vis[src] = true;
        path += to_string(src);

        for (int v : l[src]) {
            if (!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size() - to_string(src).size());
        vis[src] = false; // backtrack
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    int V = 5;
    Graph graph(V, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    graph.printAllPaths(0, 4);
    return 0;
}
