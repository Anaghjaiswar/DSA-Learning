#include<bits/stdc++.h>
using namespace std;

// concept is that if you start from a node point
// and move in two different direction then if you meet in
// at same path which suggests there is a cycle in the undirected graph




bool cycleDetect(int src, vector<int> adj[], vector<int>& vis){
    vis[src] = 1;
    // node,parent
    queue<pair<int,int>> q;
    q.push({src,-1});//bcz for the first element no parent

    while(!q.empty()){
        int node = q.front().first;
        int parent =q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if (!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(it != parent){ // means it didn't even come from it's parent.
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    bool ans = false;
    for(int i = 0; i < V; i++){
        if (!vis[i]){
            ans=cycleDetect(i,adj,vis);
        }
    }
    return ans;
            
}