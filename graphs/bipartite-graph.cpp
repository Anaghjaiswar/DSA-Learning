#include<bits/stdc++.h>
using namespace std;


// using bfs standard solution
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int totalNodes = graph.size();
        vector<int> colorTable(totalNodes, -1);
        for(int i = 0; i < totalNodes; i++){
            if (colorTable[i] == -1){

            if (bfs(i, graph, colorTable) == false) return false;   
            }
        }
        return true;
    }
private:
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& colorTable){
        // node, color value 0 or 1
        queue<pair<int, int>> q;
        q.push({i, 0});
        colorTable[i] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int clr = q.front().second;
            q.pop();

            for (int i = 0; i < graph[node].size(); i++){
                // it it is not color ye color it 
                if (colorTable[graph[node][i]] == -1){
                    colorTable[graph[node][i]] = !clr;
                    q.push({graph[node][i], !clr});
                }
                // if it is already coloured we have to check whether this is same or nnot
                else if (colorTable[graph[node][i]] == clr) return false;
            }

        }
        return true;
    }
};