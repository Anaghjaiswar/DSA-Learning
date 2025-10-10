// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                int curr = mat[i][j];

                if (i > 0 && mat[i-1][j] > curr) continue;
                if (i < m-1 && mat[i+1][j] > curr) continue;
                if (j > 0 && mat[i][j-1] > curr) continue;
                if (j < n-1 && mat[i][j+1] > curr) continue;

                return {i,j};

            }
        }
        return {-1, -1};
        
    }
};