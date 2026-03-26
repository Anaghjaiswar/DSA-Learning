#include <bits/stdc++.h>
using namespace std;

// dfs traversal means depth based search traversal 
// so you go to depth in first 

// stating node can be any 
// here you don't go breadth wise


// basically recusrion use ho gaya 


void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
    ans.push_back(node);
    vis[node] = 1;

    for(auto it: adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis, ans);
        }
    }
}



vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V, 0);
    vis[0] = 1; 

    dfs(0, adj, vis, ans);
    return ans;
}

// space complexity = O(V) + O(V) + O(V) = O(3V) ~ O(V)
// time complexity = O(V)


// meanwhile in bfs 
// time complexity = O(V) + O(2E) = O(V + E)
// space complexity = O(V) + O(V) + O(V) = O(3V) ~ O(V)  (vis array + ans array + queue)

