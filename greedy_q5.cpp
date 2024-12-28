
#include "bits/stdc++.h"
using namespace std;

const int MAX_NUM = 100000;


int N,M;
int parent[MAX_NUM];
vector<vector<pair<int, int>>> adjVertices;
vector<int> visited;
vector<int> result(200100,0);

int findSet(int v){
    if(parent[v]<0) return v;

    return parent[v]= findSet(parent[v]);
}

void unionSets(int x, int y){
    x=findSet(x);
    y=findSet(y);

    if(x!=y){
        if(parent[x]>parent[y])
            swap(x,y);

        parent[x]+=parent[y];
        parent[y]=x;
    }

}

void makeSet(int v){
    parent[v]=-1;
}

int DFS(int v){
    visited[v]=1;
    int subTreeSize=1;

    for(auto u:adjVertices[v]){
        if(visited[u.first])
            continue;

        long long subTrees=DFS(u.first);
        subTreeSize+=subTrees;

        int currentWeight=u.second;
        long long nodesInteract = subTrees*(N-subTrees);
        while(nodesInteract>0){
            if(nodesInteract%2)
                result[currentWeight]++;

            nodesInteract/=2;
            if(result[currentWeight]==2){
                result[currentWeight]=0;
                nodesInteract++;
            }
            currentWeight++;

        }
    }
    return subTreeSize;
}

int main(){
    vector<pair<int, pair<int, int> >> edge;
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int x,y,c;
        cin>>x>>y>>c;
        edge.push_back({c, {x-1, y-1}});
    }

    adjVertices.resize(N);
    sort(edge.begin(), edge.end());

    for (int i = 0; i < N; ++i) {
        makeSet(i);
    }

    for(auto u : edge){
        int from = u.second.first;
        int to = u.second.second;
        int c = u.first;

        int x = findSet(from);
        int y = findSet(to);

        if(x==y)
            continue;

        adjVertices[from].push_back({to, c});
        adjVertices[to].push_back({from, c});
        unionSets(from, to);
    }

    visited=vector<int>(N,0);
    DFS(0);

    while(result.back()==0){
        result.pop_back();
    }
    reverse(result.begin(), result.end());

    for(auto x : result)
        cout<<x;

    return 0;
}
