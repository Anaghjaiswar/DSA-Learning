#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    // 1 based indexing if minimum values of nodes start from 1 otherwise , start from zero , 
    vector<vector<int>> adj(nodes + 1, vector<int>(nodes + 1, 0));
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u>> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}