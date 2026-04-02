#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> result;

        for(int i = 0 ; i < numCourses; i++){
            if(!vis[i]){
                // if cycle is found return empty bcz all courses can't be done 
                if(dfs(i, adj, vis, pathVis, result) == true) return {};
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& result) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adj[node]){
            if (!vis[it]){
                if (dfs(it, adj, vis, pathVis, result) == true) return true;
            } else if (pathVis[it]) return true;
        }
        result.push_back(node);
        pathVis[node] = 0;
        return false;
    }
};

