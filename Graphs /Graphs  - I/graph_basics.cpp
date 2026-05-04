// Topic   : Graphs - BFS & DFS
// Concepts: Adjacency list, queue-based BFS, recursive DFS
// TC      : O(V + E)
// SC      : O(V) — vis array + recursion stack (DFS) / queue (BFS)

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for (int u = 0; u < V; u++) {
            list<int> neighbours = l[u];
            cout << u << ": ";
            for (int v : neighbours) cout << v << " ";
            cout << endl;
        }
    }

    // visit immediate neighbours first (level-order)
    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbors = l[u];
            for (int v : neighbors) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // keep going to first unvisited neighbour before backtracking
    void dfs(int u, vector<bool>& vis) {
        vis[u] = true;
        cout << u << endl;

        list<int> neighbors = l[u];
        for (int v : neighbors) {
            if (!vis[v]) dfs(v, vis);
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    cout << "BFS: ";
    graph.bfs();

    cout << "DFS:" << endl;
    vector<bool> vis(5, false);
    graph.dfs(0, vis);

    return 0;
}
