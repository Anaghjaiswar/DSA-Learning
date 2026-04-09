#include<bits/stdc++.h>
using namespace std;

// Structure to represent an edge: (destination, weight)
typedef pair<int, int> pii;

void dijkstra(int source, int n, vector<vector<pii>>& adj) {
    // dist[i] will hold the shortest distance from source to i
    vector<int> dist(n, INT_MAX);

//     pii (Data Type): Ye bas pair<int, int> ka chota naam hai. Isme hum {distance, node} rakhte hain. 
//     Kyunki C++ pairs ko pehle element (distance) se compare karta hai, toh sorting distance ke basis pe hogi.

// vector<pii> (Container): Priority queue ko apna data kahin toh save karna padega na? T 
// oh hum bol rahe hain ki "Bhai, vector use kar le data rakhne ke liye."

// greater<pii> (The Magic Trick): Ye sabse zaroori hai. C++ ki default fitrat hai bada number upar 
// rakhna (less). greater likhne se hum uski fitrat badal dete hain taaki wo sabse chota number top pe
//  rakhe.
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0; 
    pq.push({0, source});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        // If we found a shorter path to u already, skip this stale entry
        if (distance > dist[node]) continue;

        for (auto& edge : adj[node]) {
            int neighbour = edge.first;
            int wt = edge.second;

            if (dist[neighbour] > dist[node] + wt){
                dist[neighbour] = dist[node] + wt;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    // Output results
    cout << "Node \t Distance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " \t\t " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }

} 