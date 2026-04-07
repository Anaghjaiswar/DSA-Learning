#include<bits/stdc++.h>
using namespace std;

// Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.



// Find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // Create an adjacency list of size N to store the undirected graph
    vector<int> adj[N]; 

    // Build the graph by adding edges to the adjacency list
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]); 
        adj[it[1]].push_back(it[0]); 
    }

    vector<int> dist(N, 1e9);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        
        }
    }

    vector<int> ans(N, -1);

    for(int i = 0; i < N; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    
    }

    return ans;

}