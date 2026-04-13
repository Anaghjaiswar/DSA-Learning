#include<bits/stdc++.h>
using namespace std;



class Solution {
    typedef pair<int, pair<int, int>> pipii;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // 2D distance array
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // Min-heap:{effort, {r, c}}
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            int currentEffort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == rows - 1 && c == cols - 1) return currentEffort;

            if (currentEffort > dist[r][c]) continue;

           for (int i = 0; i < 4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];

                if (isValid(newR, newC, rows, cols)) {
                    // Naya effort = purana effort aur current jump ka max
                    int effort = max(currentEffort, abs(heights[r][c] - heights[newR][newC]));

                    if (effort < dist[newR][newC]) {
                        dist[newR][newC] = effort;
                        pq.push({effort, {newR, newC}});
                    }
                }
            }
        }
        return 0;
    }

private:
    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }
};