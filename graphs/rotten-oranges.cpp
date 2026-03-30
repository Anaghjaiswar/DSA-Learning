
#include <bits/stdc++.h>
using namespace std;

// dekho hpga kya ek gand i machli jsi tarah talab k oganda karti hai 
// thik usi tarah ek rotten orange ek fresh orang ko sada dega 
// gar woh friesh orange uske left,right,top ya botttom me hai  toh

// har ek sec me use sade hue santre ke padosi sad jaate hai toh kitne der me sare padosi sad jayeneg 



// ek vsiited arra ban lo jisme sab hoga ki initilayy kitne sade hai , unko quue me daall do 
// timer zero ke saath, phir usko bahi standar dfs karna hai agar sada nahi hai toh time badate jayo 

// max time return kardo agar sare sad gaye nahi toh -1 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // {{r,c}, t}
        queue<pair<pair<int, int>,int>> q;
        vector<vector<int>> visArr(rows, vector<int>(cols, 0));

        int cntfresh = 0;
        for(int i = 0; i< rows; i++){
            for(int j = 0; j< cols; j++){
                if (grid[i][j] == 2){
                    visArr[i][j] = 2;
                    q.push({{i,j},0});
                }

                else if (grid[i][j] == 1){
                    cntfresh++;
                }

            }
        }
        int time = 0;
        int cntProcessed = 0;
        int drow[] = {-1, 0, +1, 0}; 
        int dcol[] = {0, -1, 0, +1};
        while(!q.empty()){
            int r = q.front().first.first; //row
            int c = q.front().first.second; //col
            int t = q.front().second; //time
            q.pop();
            time = max(time, t);

            for(int i = 0; i < 4; i++){
                int nRow = r + drow[i];
                int nCol = c + dcol[i];

                if (
                    (nRow >=0 && nRow < rows) && 
                    (nCol >= 0 && nCol < cols) &&
                    (visArr[nRow][nCol] == 0) && // it should not be visted 
                    (grid[nRow][nCol] == 1) //  check if it's a fresh orange
                ){
                    q.push({{nRow,nCol}, t+1});
                    visArr[nRow][nCol] = 2;
                    cntProcessed++;
                }
            }

        }

        if (cntfresh != cntProcessed) return -1;
        return time;


    }
};
