// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       int n = matrix[0].size();

        // row-wise binarysearch
        int low = 0;
        int high = m-1;
        while(low<=high){
            int row = (low + high)/2;
            if (target < matrix[row][0]) high = row - 1;
            else if(target > matrix[row][n-1]) low = row + 1;
            else return bsonrow(matrix[row], target);
        }
        return false;
    }
private:
    bool bsonrow( vector<int>& row, int target){
        int low = 0;
        int high = row.size()-1;

        while(low<=high){
            int mid = (low + high)/2;
            if(row[mid] == target) return true;
            else if (row[mid] < target) low = mid+1;
            else high = mid - 1;
        }
        return false;
    }
};