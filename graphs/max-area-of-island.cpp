#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // we need to create a visted matrix
        int max_area = 0;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // this will trigger for starting points of isalnds
                if (!vis[row][col] && grid[row][col] == 1) {
                    int area = 0;
                    area = dfs(row, col, grid, vis);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }

public:
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis) {
        int rows = grid.size();
        int cols = grid[0].size();

        vis[row][col] = 1;
        int area = 1; // Current cell ko count kiya

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            // CHECK: 1. Is the neighbor within matrix boundaries?
            //        2. Is it land (1)?
            //        3. Is it unvisited?
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                area += dfs(nRow, nCol, grid, vis);
            }
        }
        return area;
    }
};