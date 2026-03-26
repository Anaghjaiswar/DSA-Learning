
#include <bits/stdc++.h>
using namespace std;



// basically hai bfs traversal 

// bas disconnected componenrs ghai unak count return karna ahi toh simple for loop me aage badho 
// toh count badhate jaayo.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalVertices = isConnected.size();
        int count = 0;
        vector<int> vis(totalVertices, 0);

        // Looping through all nodes to handle disconnected components
        for (int i = 0; i < totalVertices; i++) {
            if (!vis[i]) {
                count++;
                bfs(i, isConnected, vis);
            } 
        }
        return count;
    }
private:
    void bfs(int startNode, vector<vector<int>>& adj, vector<int>& vis){
        queue<int> q;
        q.push(startNode);
        vis[startNode] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                if (adj[node][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }

        }
    }
};