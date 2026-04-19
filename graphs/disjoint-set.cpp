#include<bits/stdc++.h>
using namespace std;

// 1----2---3---4

// 5---6---7

// The question is whether node 1 and node 5 are in the same component or not.

// Approach:

// Now, in order to solve this question we can use either the DFS or BFS traversal technique like if we traverse the components of the graph we can find that node 1 and node 5 are not in the same component. This is actually the brute force approach whose time complexity is O(N+E)(N = no. of nodes, E = no. of edges). But using a Disjoint Set data structure we can solve this same problem in constant time.

// The disjoint Set data structure is generally used for dynamic graphs. 


// Functionalities of Disjoint Set data structure:
// The disjoint set data structure generally provides two types of functionalities:

// Finding the parent for a particular node (findPar())
// Union (in broad terms this method basically adds an edge between two nodes)
// Union by rank
// Union by size
// First, we will be discussing Union by rank and then Union by size.


class DisjointSet {
    vector<int> rank,parent,size;
public:
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