#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m-1;
        int top = 0, bottom = n-1;

        vector<int> ans;


        while(top<= bottom && left <=right){
            // right movement

            // yaha pe condition check isliye nahi lagaye bcz abhi update ya delete nahi kar rahe aur while loop me toh check kar hi rahe hai.
            for (int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // bottom movement
            // ya pe condition isliye nahi laagaye kyuki for loop me hi check ho ja raha hai ki top <= bottom hai ki nahi aur while loop me left , right , 
            // aur usko alag se check karne ki zarurat nahi bcz abhi left ya right me kuch update ya delete nahi kiya hai.
            for (int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // left movement
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // top movement
            if(left <= right){
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};