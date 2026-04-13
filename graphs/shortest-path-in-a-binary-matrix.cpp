



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    
        if (n == 1) return 1;


        vector<vector<int>> dist(n, vector<int>(n, -1));
                // row, col
        queue<pair<int,int>> q;

        q.push({0,0});
        dist[0][0] = 1; // we have to count the start also

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++){
                int row = r + dr[i];
                int col = c + dc[i];
                                                        // should not be vis. earlier
                if (isValid(row,col,n,n) && grid[row][col] == 0 && dist[row][col] == -1){
                    dist[row][col] = dist[r][c] + 1;

                    if (row == n - 1 && col == n - 1) return dist[row][col];
                    q.push({row,col});
                }
            }
        }
        return -1;

    }
private:
    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }
};