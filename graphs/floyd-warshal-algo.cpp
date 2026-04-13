#include<bits/stdc++.h>
using namespace std;

// we will implement floyd - warshal algorithm 
// tc=O(n^3)


void floydWarshall(vector<vector<int>>& matrix){
    int n = matrix.size();

    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            if(i == j){
                matrix[i][j] = 0;
            }
        }
    }


    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Only update if k provides a valid path
                if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }


}