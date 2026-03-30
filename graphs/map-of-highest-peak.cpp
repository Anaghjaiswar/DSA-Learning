#include<bits/stdc++.h>
using namespace std;



// point is we need to caclulate nearest distance from one , 
// i.e. we can use bfs algorithm , what will it do , inintally all the ones we will insert in ti 
// from that we go to one levl from all the ones if it's a zero we replace it with 1 , and pop it
// similairy from ones wherever we fruther to find zeroes we write + 1 = 2



// same as DISTANCE OF NEAREST CELL HAVING ONE

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int n = mat.size();
        int m = mat[0].size();

        // we will use bfs for this
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = 0;
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        bfsalgo(mat, q);
        return mat;
    }

private:
    void bfsalgo(vector<vector<int>>& mat, queue<pair<int, int>>& q) {
        int n = mat.size();
        int m = mat[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int neighRow = row + delRow[i];
                int neighCol = col + delCol[i];

                if (neighRow >= 0 && neighRow < n && neighCol >= 0 &&
                    neighCol < m && mat[neighRow][neighCol] == -1) {
                    mat[neighRow][neighCol] = mat[row][col] + 1;
                    q.push({neighRow, neighCol});
                }
            }
        }
    }
};