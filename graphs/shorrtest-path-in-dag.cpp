#include<bits/stdc++.h>
using namespace std;


// we have to find the shortest path in a DAG, we will standard topo sort using dfs

// iven a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.



// Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.


void dfs(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st){
    vis[node]=1;

    for(auto it: adj[node]){
        if(!vis[it.first]){
            dfs(it.first, adj, vis, st);
        }
    }

    st.push(node);
}

vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // do the topo sort using stack
    vector<int> vis(N,0);
    stack<int> st;

    for(int i = 0; i < N; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        
        }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;


    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[v] > dist[node] + wt){
                dist[v] = dist[node] + wt;
            }


        }
    }

    // Replace all unreachable nodes' distances with -1
    for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) {
            dist[i] = -1;
        }
    }

    return dist;

}


    