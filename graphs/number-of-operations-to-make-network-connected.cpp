#include<bits/stdc++.h>
using namespace std;



class DisjointSet {
public:
    vector<int> rank,parent,size;
    // constructor call
    DisjointSet(int n){
        rank.resize(n+1,0);  // for union by rank
        parent.resize(n+1); 
        size.resize(n+1);  // for union by size

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]) return node;
        // path compression -> we directly assign the parent node after we visit it once
        return parent[node] = findUltimateParent(parent[node]);
    
    }

    void unionByRank(int u, int v){
        // u-v is a edge
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        

        // if for both u and v ultimate parent is same means they are already in same component
        // we don't need to union them
        if (ulp_u == ulp_v) return;

        // if rank of parent of u is smaller than rank of parent of v then make v parent of u
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        // if rank of parent of v is smaller than rank of parent of u then make u parent of v
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        //  if rank of parent of u and v is same then make anyone parent of other and increase the rank of that parent by 1
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        
        if (ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // to connect n components we need min of n-1 edges
        // If edges are less than n - 1, we can't connect
        if(connections.size() < n - 1) return -1;

        DisjointSet ds(n);

        for(auto edge: connections){
            ds.unionBySize(edge[0],edge[1]);
        }

        // count noof unique components
        // possible unique parents will be the answer to this
        int count = 0;
        for(int i = 0; i < n; i++) {

            // yeh totoal psooible components hai 
            if(ds.parent[i] == i) count++; // Jo node khud ka parent hai, wahi component ka head hai
        }

        // inko jodne ke liye min itni edges chhaiye
        return count - 1;

    }
};
