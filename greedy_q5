#include "bits/stdc++.h"
using namespace std;

const long long INFIN = 1e18;    //to assign infinity to all vertices at the beginnig 
const int MAX_Num = 100000;

struct Edge{
    int to;
    long long weight;
};

vector<Edge>adjVertices[MAX_Num];
void dijkstra(int source, int n, vector<long long >& distance){
    distance[source]=0;   // source node

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;
    pq.push({0, source});

    while (!pq.empty()){
        long long dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist>distance[u])  //no need to change because it's already smaller
            continue;

        for(const auto& edge : adjVertices[u]){
            long long w = edge.weight;
            int v = edge.to;

            if(distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }

        }
    }

}

int main(){
    int N, M;
    cin>>N>>M;
    //build the graph
    for(int i=0; i<M; i++){
        int v1, v2, C;
        long long weight =1;
        cin>>v1>>v2>>C;
        v1--;    //to put them in thier right index
        v2--;
        for (int j = 0; j < C; j++) {
            weight*=2;              //2**C
        }
        adjVertices[v1].push_back({v2, weight});
        adjVertices[v2].push_back({v1, weight});

    }

    long long sum =0;
    for (int i = 0; i < N; ++i) {
        vector<long long> distance(N, INFIN);
        dijkstra(i, N, distance);
        for (int j = i+1; j < N; ++j) {
            sum+=distance[j];      //the min distance between source and vertix
        }
    }

    string sumInBinary = "";
    while(sum>0){
        sumInBinary = char('0'+(sum%2) )+sumInBinary;
        sum/=2;
    }

    if(sumInBinary.empty()){   //the sum is zero
        sumInBinary="0";
    }

    cout<<sumInBinary<<endl;

    return 0;
}

