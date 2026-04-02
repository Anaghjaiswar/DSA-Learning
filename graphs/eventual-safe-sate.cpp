#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> vis(nodes, 0);
        vector<int> pathVis(nodes, 0);
        vector<int> result;

        for(int i = 0 ; i < nodes; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, result);
            }
        }
        sort(result.begin(),result.end());
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


int main() {
    Solution sol;

    // Test Case: Disconnected Safe Path vs Polluted Path
    // Node 0 -> 1 (Cycle)
    // Node 2 -> 3 -> 4 (Safe Path, but 3 points to 0)
    // graph[0] = {1}, graph[1] = {1}, graph[2] = {3}, graph[3] = {4, 0}, graph[4] = {}
    
    vector<vector<int>> graph = {{1}, {1}, {3}, {4, 0}, {}};
    
    // Expected Safe Nodes: {4} 
    // Node 2, 3, 0, 1 are all unsafe because they lead to cycle at 1.
    
    vector<int> result = sol.eventualSafeNodes(graph);

    cout << "Safe Nodes found: ";
    for(int node : result) cout << node << " ";
    cout << endl;

    return 0;
}