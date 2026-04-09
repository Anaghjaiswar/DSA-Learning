#include<bits/stdc++.h>
using namespace std;

// we will print dijkstra path using priorty queue distance matrix and cache parent array


vector<int> shortestPath(int N, int M, vector<vector<int>>& edges, int src,int target){
    vector<pair<int, int>> adj[N+1];

    for (auto it: edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N+1, 1e9);

    vector<int> parent(N+1);
    for(int i = 0; i <= N;i++) parent[i]=i;

    dist[src]=0;
    pq.push({0, src});

    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        if (dis > dist[node]) continue;

        for(auto it: adj[node]){
            int neighbourNode = it.first;
            int edgeWt = it.second;

            if(dist[neighbourNode] > dist[node] + edgeWt){
                dist[neighbourNode] = dist[node] + edgeWt;
                pq.push({dist[neighbourNode], neighbourNode});
                parent[neighbourNode] = node;
            }
        }
    }

    if (dist[target] == 1e9) return {-1}; // Path doesn't exist

    vector<int> path;
    int curr = target;
    
    while (parent[curr] != curr) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(src); // Add the source node at the end
    
    reverse(path.begin(), path.end());
    return path;
}