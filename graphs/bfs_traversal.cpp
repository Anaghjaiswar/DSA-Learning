#include <bits/stdc++.h>
using namespace std;

// Helper function to perform BFS from a specific starting node  if purely connected
void bfs(int startNode, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
    queue<int> q;
    q.push(startNode);
    vis[startNode] = 1;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);

        for (auto neighbor : adj[currNode]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}


// attachhed for disconnected part
vector<int> bfsTraversalOfGraph(int totalVertices, vector<vector<int>> adj) {
    vector<int> ans;
    vector<int> vis(totalVertices, 0);

    // Looping through all nodes to handle disconnected components
    for (int i = 0; i < totalVertices; i++) {
        if (!vis[i]) {
            bfs(i, adj, vis, ans);
        } 
    }
    return ans;
}
int main() {
    int numVertices, numEdges;

    // 1. Prompt for graph dimensions
    cout << "Enter the number of vertices and edges: ";
    if (!(cin >> numVertices >> numEdges)) {
        return 0;
    }

    // Initialize adjacency list with the correct size
    vector<vector<int>> adjList(numVertices);

    // 2. Prompt for each edge connection
    cout << "Enter " << numEdges << " edges (format: source destination):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, w;
        if (cin >> u >> w) {
            // Check to ensure inputs are within valid range [0, numVertices-1]
            if (u >= 0 && u < numVertices && w >= 0 && w < numVertices) {
                adjList[u].push_back(w);
                adjList[w].push_back(u);
            } else {
                cout << "Warning: Edge (" << u << "," << w << ") is out of bounds!" << endl;
            }
        }
    }

    // 3. Perform BFS
    vector<int> bfsResult = bfsTraversalOfGraph(numVertices, adjList);

    // 4. Output the final traversal sequence
    cout << "\nBFS Traversal Order: ";
    for (size_t i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult[i] << (i == bfsResult.size() - 1 ? "" : " -> ");
    }
    cout << endl;

    return 0;
}

// bfs of a graph
// bfs means breadth wise
// usually graphs are 1 - based or 0 - based
// you just need to make sure 

// doesn't means it always starts from top , 

// it goes equivalent in the breadth

// from a node level nodees are seen and then then inserted

// /intial configuration needed for bfs traversal
// so starting node is give to you clearly take a QUEUE data structure.
// you need to create a vsited array 
// and since the graph is one based and the node is numbered till 9 
// so keep you array from 0 to 9 both involving .
// whatever is the starting node go over their and mark it as one everyone 
// else mark it as zero.


