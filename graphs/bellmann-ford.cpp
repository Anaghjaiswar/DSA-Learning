#include<bits/stdc++.h>
using namespace std;

vector<int>bellman_ford(int V,vector<vector<int>>&edges,int src){
    vector<int>dist(V,1e9);
    dist[src]=0;

    bool change_occured = false;
    // we will loop for n-1 times
    for(int i=0;i<V-1;i++){
        change_occured = false;
        for(auto it:edges){
            int from = it[0];
            int to = it[1];
            int wt = it[2];

            if (dist[from] != 1e9 && dist[from] + wt < dist[to]){
                dist[to] = dist[from] + wt;
                change_occured = true;
            
            }
        }
        if(change_occured == false) break;
    }

    // negative cycledetction
    for(auto it:edges){
        int from = it[0];
        int to = it[1];
        int wt = it[2];

        if (dist[from] != 1e9 && dist[from] + wt < dist[to]){
            // if we can still relax means a neagaitve cycle is their we can return -1
            dist[to] = -1;
        }
    }

    return dist;
}
