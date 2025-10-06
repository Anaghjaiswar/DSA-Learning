
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 


#include <bits/stdc++.h>
using namespace std;


bool BS(vector<int>& row, int target){
    int low = 0;
    int high = row.size() - 1;

    while(low<=high){
        int mid = (low+high)/2;
        if(row[mid] == target) return true;
        else if(row[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = 0; i < rows; i++){
        if(BS(matrix[i], target)) return true;
        else continue;
    }
    return false;
}


// if we stRT THINKING OF THE OPTIMAL SOLUTION TAKE THE EXAMPLE OF THE GIVEN MATRIX 
// CONSIDER TO TOP RIGHT CORENR ELEMNT , ELEMENT TO THE LEFT ARE SMALLERR THAN IT AND 
// ELEMENT TO BOTTOM OF IT ARE GREATER THAN IT , SO IF YOU CONSIDER a  array from 1,4,7,11,15,19,22,24,30
// it's sorted ,we can apply bs to it 

bool search(vector<vector<int>>& matrix , int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = cols - 1;

    while(row < rows && col >= 0){
        int element = matrix[row][col];  // you take the top -right element 
        cout << element <<endl; 

        // if it's the target return true
        if(element == target) return true;
        
        // if element < target , it obvious then it's gonna lie in that top row as the target can be their 
        // no possibility of finding it in the last col
        else if(element > target) col--;

        // if element > target , it obvious then it's gonna lie in that last column as the target can be their 
        // no possibility of finding it in that particular row

        else row++;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix ={
                                {1 ,4 ,7 ,11,15},
                                {2 ,5 ,8 ,12,19},
                                {3 ,6 ,9 ,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}
                            };

    int target =3;
    if(search(matrix, target))
        cout << "Found\n";
    else
        cout << "Not found\n";
    return 0;                   
}

