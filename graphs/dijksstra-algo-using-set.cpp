#include<bits/stdc++.h>
using namespace std;


//  we will implement dijkrsta algorithm using set

void dijkstra(int src, vector<pair<int, int>> adj[], int V){
    set<pair<int,int>>st;
    vector<int> dist(V,1e9);

    dist[src]=0;
    st.insert({0,src});

    while(!st.empty()){
        auto it = *st.begin();
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it: adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node]+wt < dist[v]){
                if (dist[v] != 1e9) st.erase({dist[v], v});
                dist[v] = dist[node]+wt;
                st.insert({dist[v], v});

            }
        }
    }
    return;
} 