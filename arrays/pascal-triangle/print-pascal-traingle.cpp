#include<bits/stdc++.h>
using namespace std;

// brute force approach
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 1; row <= numRows; row++){
            vector <int> temp;
            for(int col = 1; col <= row; col++){
                temp.push_back(NcR(row-1,col-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
private:
    int NcR(int row, int col){
        int result = 1;
        for(int i = 0; i < col; i++){
            result = (result * (row-i))/(i+1);
        }
        return result;
    }
};


// better approach
vector<int> createPascalTriangle(int rowNumber){
    vector <int> temp;
    int ans = 1; 
    temp.push_back(ans);
    for (int col = 1; col < rowNumber; col++){
        ans = (ans * (rowNumber - col))/col;
        temp.push_back(ans);
    }
    return temp;
}


int main(){
    int n;
    cout<< "Enter n:";
    cin >> n;

    vector <vector<int>> ans;
    for(int i = 1; i <= n; i++){
        vector<int> temp = createPascalTriangle(i);
        ans.push_back(temp);
    }
    for (auto it: ans){
        for (auto num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
}