#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;
    
    Graph (int V){
        this->V = V;

        for(int i=0; i<V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int X){
        if(par[X] == X){
            return X;
        }
        return par[X] = find(par[X]);
    }
    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA] ++ ;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }
    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u,v,wt));
    }

    void kruskals(){ //O(ELogE)
        sort(edges.begin(), edges.end(), [](Edge &a, Edge&b){
            return a.wt < b.wt; // O(ElogE)
        });
        int minCost = 0;
        int count = 0;
        for(int i=0; i<edges.size() && count < V-1; i++){
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){
                // cycle does not exists
                unionByRank(parU,parV);
                minCost += e.wt;
                count ++;
            }
        }
        cout << "min cost : " << minCost << endl;
    }
};
