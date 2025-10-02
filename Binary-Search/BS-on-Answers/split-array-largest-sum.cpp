// https://leetcode.com/problems/split-array-largest-sum/description/
// You are given an array of integers nums and an integer k. You should split the array into k non-empty continuous subarrays.
// Write an algorithm to minimize the largest sum among these k subarrays.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = sum(nums);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int splitcount = requiredSplits(nums, mid);
            if(splitcount <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
private:
    int sum(vector<int>& nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int requiredSplits(vector<int>& nums, int maxSumAllowed){
        int splits = 1;
        int currentSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(currentSum + nums[i] <= maxSumAllowed){
                currentSum += nums[i];
            }
            else{
                splits++;
                currentSum = nums[i];
            }
        }
        return splits;
    }
};