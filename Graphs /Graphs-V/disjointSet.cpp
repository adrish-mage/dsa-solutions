#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSet(int n){
        this->n = n;
        for(int i=0; i<n; i++){
            par.push_back(i) ; // initially each element is its own parent
            rank.push_back(0);
        }
    }
    int find(int X){
        if(par[X] == X){
            return X;
        }
        return par[X] = find(par[X]); //path compression
    }
    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[a]++;
            
        }else if (rank[parA] > rank[parB]){
            par[parB] = parA;
            
        }else{
            par[parA] = parB;
            
        }
    }
};

int main(){
    DisjointSet dj(6);
    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl;
    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0, 4);
    return 0;
}
