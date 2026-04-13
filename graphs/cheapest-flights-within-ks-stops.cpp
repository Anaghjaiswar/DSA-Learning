

#include<bits/stdc++.h>
using namespace std;







class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // node,price
        vector<pair<int,int>> adj[n];

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // {stops,{node,cost}}
        queue<pair<int,pair<int,int>>> q;
        q.push ({0,{src,0}});

        vector<int>costMatrix(n,1e9);
        costMatrix[src]=0;

        while(!q.empty()){
            auto it = q.front();
            int currStops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();

            if(currStops > k) continue;

            for(auto it: adj[node]){
                int nhbrNode=it.first;
                int price=it.second;

                if( (price+cost) < costMatrix[nhbrNode] && currStops <= k){
                    costMatrix[nhbrNode] = price+cost;
                    q.push({currStops+1,{nhbrNode,price+cost}});
                }
            }
        }
        if(costMatrix[dst]==1e9) return {-1};

        return costMatrix[dst];

    }
};

