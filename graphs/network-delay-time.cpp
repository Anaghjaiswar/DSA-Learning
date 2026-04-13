


#include <bits/stdc++.h>
using namespace std;




class Solution {
    typedef pair<int, int> pii;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {

        vector<vector<pii>> adj(n + 1); 
        for (auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n+1, INT_MAX);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            // If we found a shorter path to u already, skip this stale entry
            if (distance > dist[node])
                continue;

            for (auto& edge : adj[node]) {
                int neighbour = edge.first;
                int wt = edge.second;

                if (dist[neighbour] > dist[node] + wt) {
                    dist[neighbour] = dist[node] + wt;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        int max_possible = 0;
        for (int i = 1 ;i <= n; i++){
            if (dist[i] == INT_MAX) return -1;
            max_possible = max(max_possible, dist[i]);
        }
        return max_possible;
    }
};