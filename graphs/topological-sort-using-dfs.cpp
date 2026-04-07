#include<bits/stdc++.h>
using namespace std;


bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(vis[it] == 0){
            if(dfs(it, adj, vis, st)) return false;
        }
        else if(vis[it] == 1) return false;
    }
    vis[node] = 2; 
    st.push(node);
    return true;
}


vector<int> topoSort(vector<vector<int>> adj, int V){
    vector<int> vis(V, 0);
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if (dfs(i, adj, vis, st)) return {};
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;

}