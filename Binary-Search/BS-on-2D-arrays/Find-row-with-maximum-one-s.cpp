#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time complexity: O(n*m)
int rowWithMax1s(vector<vector<int>> &mat)
{
    int index = -1;
    // int countRow = -1
    int n = mat.size();
    int m = mat[0].size();
    int maxCount = -1;
    for (int i = 0; i < n; i++)
    {
        int countRow = 0;
        for (int j = 0; j < m; j++)
        {
            countRow += mat[i][j];
        }
        if (countRow > maxCount)
        {
            maxCount = countRow;
            index = i;
        }
    }
    if (maxCount == 0)
        return -1;
    return index;
}

int rowwithmax1sBs(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxCount = -1;
    int index = -1;
    for (int i = 0; i < n; i++) // har row ko dekh
    {
        int low = 0;
        int high = m - 1;
        if(mat[i][m-1] == 0) continue;  // agar row ka last element hi zero hai toh mujhe uske liye bs chalana hi nahi hai
        int firstOccurence = -1;

        // check the lowerbound
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mat[i][mid] >= 1){
                firstOccurence = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }

        int countRow = 0;
        countRow += (m-firstOccurence);
        if(countRow > maxCount){
            maxCount = countRow;
            index = i;
        } 
    }
    if (maxCount == 0) return -1;
    return index;
}


int main()
{
    vector<vector<int>> mat = {{0, 0, 0, 1},
                               {0, 1, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    cout << rowwithmax1sBs(mat);
}
