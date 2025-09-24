#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            int result = calculateSumafterCeilDivision(nums, mid);
            if(result <= threshold){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
private:
    int calculateSumafterCeilDivision(vector<int>& nums, int mid){
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum += (nums[i] + mid - 1)/mid;
        }
        return totalSum;
    }
};