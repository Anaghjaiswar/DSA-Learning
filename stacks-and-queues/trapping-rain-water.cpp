
// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105



// Array:

// [0,1,0,2,1,0,1,3,2,1,2,1]

// Build arrays

// leftMax

// [0,1,1,2,2,2,2,3,3,3,3,3]


// rightMax

// [3,3,3,3,3,3,3,3,2,2,2,1]

// Water formula
// water[i] = min(leftMax[i], rightMax[i]) - height[i]

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nxtGre = nextGreatest(height);
        vector<int> preGre = previousGreatest(height);

        int waterSum = 0;
        for(int i = 0; i < n; i++){
            int water= min(nxtGre[i],preGre[i]) - height[i]; 
            if (water > 0) waterSum+=water;
        }
        return waterSum;


    }
private:
    vector<int> nextGreatest(vector<int>& arr){
        int n = arr.size();
        vector<int> ng(n);

        ng[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            ng[i] = max(arr[i], ng[i+1]);
        }
        return ng;
    }
    vector<int> previousGreatest(vector<int>& arr){
        int n = arr.size();
        vector<int> pg(n);

        pg[0] = arr[0];
        for(int i = 1; i < n; i++){
            pg[i] = max(arr[i], pg[i-1]);
        }
        return pg;
    }
};