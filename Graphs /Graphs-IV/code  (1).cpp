#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt){
        this->v =  v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> graph, int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap -> pair : { dist[v] , v }
    vector<int> dist (V,INT_MAX);
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vector<Edge> edges = graph[u];
        for(Edge e : edges){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }

    for(int d : dist){
        cout << d << " ";
    }
    cout << endl;
}

void bellmanFord(int src,vector<vector<Edge>> graph, int V){
    vector<int>dist(V,INT_MAX);
    dist[src] = 0;
    
    for(int i=0; i<V-1; i++){ // V-1 times
        for(int u=0; u<V; u++){
            for(Edge e : graph[u]){
               if(dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                } 
            }
        }
    }
    for(int d : dist){
        cout << d << " ";
    }
    cout << endl;
}

class Graph {
    int V;
    list<pair<int,int>>* l;
    bool isUndir;
public:
    Graph(int V, bool isundir =  true){
        this->V = V;
        l = new list<pair<int,int>> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt){ // unDir : u --- v ; Dir : u ---> v
        l[u].push_back(make_pair(v,wt));
        if(isUndir){
            l[v].push_back(make_pair(u,wt));
        }
       
    }

    void primsAlgo(int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ; //(wt,u) ->min heap
        vector<bool> mst (V,false);
        pq.push(make_pair(0,src));
        int ans = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans += wt;
                for(pair<int,int> n : l[u]){
                    pq.push(make_pair(n.second,n.first));
                }
            }
        }
    }
};

int main(){
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    dijkstra(0,graph,V);

    return 0;
}