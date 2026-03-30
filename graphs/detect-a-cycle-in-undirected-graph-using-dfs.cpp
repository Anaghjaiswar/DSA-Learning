#include<bits/stdc++.h>
using namespace std;

// we have to detect a cycle in undirected graph using dfs
// what we can do we call a function dfs(startNode, -1), -1 as it's parent
// and then we keep calling but by maintaing a visited array
// anywhere if we see it's already visted and it's not the parent /
// then that is a cycle we keep onn returning true


bool detectCycle(int startNode, vector<int> adj[], vector<int>& vis){
    vis[startNode] = 1;

    for (auto it: adj[startNode]){
        if (!vis[it]){
            if (detectCycle(it, adj, vis)) return true;
        }
        else if (it != startNode) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    bool ans = false;
    for (int i = 0; i < V; i++){
        if (!vis[i]){
            ans = detectCycle(i, adj, vis);
        }
    
    }
    return ans;
}