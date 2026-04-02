#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0 ; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true) return false;
            }
        }
        return true;

    }
private:
bool dfs(int startNode, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
    vis[startNode] = 1;
    pathVis[startNode] = 1;
    for(auto it: adj[startNode]){
        // if it is not visited at all vsit it
        if (!vis[it]){
            if(dfs(it, adj, vis, pathVis) == true) return true;
        }
        // if it is visited , and also on the same path it is visted then cycle
        else if(pathVis[it]) return true;
    }
    pathVis[startNode] = 0;
    return false;
}
};