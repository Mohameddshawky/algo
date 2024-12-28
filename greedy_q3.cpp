#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

bool isValidPath(int n, vector<vector<int>>edges,int source, int destination){
    if (source == destination)
        return true;
    unordered_map<int,vector<int>> vertexAdjacencyList;
    //{0,1}   -->  0--->1      1--->0
    //{1,2}   -->  0--->1      1--->0,2     2--->1
    //{2,0}   -->  0--->1,2    1--->0,2     2--->1,0

    //{0, 1}  -->  0--->1      1--->0
    //{0, 2}  -->  0--->1,2    1--->0       2--->0
    //{3, 5}  -->  0--->1,2    1--->0       2--->0    3--->5    5--->3
    //{5, 4}  -->  0--->1,2    1--->0       2--->0    3--->5    5--->3,4    4--->5
    //{4, 3}  -->  0--->1,2    1--->0       2--->0    3--->5,4  5--->3,4    4--->5,3
    for(vector edge:edges){
        vertexAdjacencyList[edge[0]].push_back(edge[1]);
        vertexAdjacencyList[edge[1]].push_back(edge[0]);
    }
    unordered_set<int> visited;
    //breadth-first search (BFS)
    queue<int> BFS_queue;
    BFS_queue.push(source);
    visited.insert(source);

    // Visit all adjacent vertices
    while(!BFS_queue.empty()){
        int vertex = BFS_queue.front();
        BFS_queue.pop();

        for(int adjVertex : vertexAdjacencyList[vertex]){
            if(adjVertex == destination)
                return true;
            if(visited.find(adjVertex) == visited.end()){
                BFS_queue.push(adjVertex);
                visited.insert(adjVertex);
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int n = 3;
//    vector <vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
//    int source = 0;
//    int destination = 2;
    int n = 6;
    vector <vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source = 0;
    int destination = 5;

    if (isValidPath(n, edges, source, destination))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
