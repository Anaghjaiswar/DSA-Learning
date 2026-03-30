#include<bits/stdc++.h>
using namespace std;


// number of islands problem is similar to number of provinces
// but here actually matrix is given
// so ek peice aur uske chaaro 8 corners ko tooh ho ayeg kis bhi traversal se

// toh pure matrixe me travers kiya toh non visited aaye pehle baar ware satring verticer honge 
// dfs ya bfs traaversal kek


void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
    int rows = grid.size();
    int cols = grid[0].size();

    vis[row][col] = 1;
    
    // we need to traverse in the neighbours
    for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
        for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
            int nRow = row + deltaRow;
            int nCol = col + deltaCol;

            // CHECK: 1. Is the neighbor within matrix boundaries?
            //        2. Is it land (1)?
            //        3. Is it unvisited?
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols 
                && grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                dfs(nRow, nCol, grid, vis);
            }
        }
    }
    
}

int numslands(vector<vector<int>>& grid){
    int rows = grid.size();
    int cols = grid[0].size();
    

    // we need to create a visted matrix
    vector<vector<int>> vis(rows, vector<int>(cols, 0));
    int count = 0;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            
            // this will trigger for starting points of isalnds 
            if (!vis[row][col] && grid[row][col] == 1){
                count++;
                dfs(row, col, grid, vis);
            }
        
        }
    }
    return count;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // we need to create a visted matrix
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int count = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // this will trigger for starting points of isalnds
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    dfs(row, col, grid, vis);
                }
            }
        }
        return count;
    }

private:
    void dfs(int row, int col, vector<vector<char>>& grid,vector<vector<int>>& vis) {
        int rows = grid.size();
        int cols = grid[0].size();

        vis[row][col] = 1;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                dfs(nRow, nCol, grid, vis);
            }
        }
    }
};