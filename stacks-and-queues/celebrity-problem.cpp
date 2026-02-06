
#include <bits/stdc++.h>
using namespace std;

/*
A celebrity is a person who is known by everyone else at the party but 
does not know anyone in return. Given a square matrix M of size N x N 
where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine 
if there is a celebrity at the party. Return the index of the celebrity or 
-1 if no such person exists.

Note that M[i][i] is always 0.
*/

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int rows = M.size();
        int cols = M[0].size();

        int top = 0;
        int down = rows - 1;



        while(top < down){

            // does the top knows down
            if (M[top][down] == 1){
                top++;
            }
            // if down knows top
            else if (M[down][top] == 1){
                down--;
            }
            // if they don't know each other
            else{
                top++;
                down--;
            }
        }

        if (top > down) return -1;

        // cross check if it's th celebrity or not
        for(int i = 0; i< cols; i++){
            if (i == top) continue; // don't check the diagonal
            if((M[top][i] == 0) && (M[i][top] == 1)){

            }
            else return -1;
        }

        return top;
        
    }
};
