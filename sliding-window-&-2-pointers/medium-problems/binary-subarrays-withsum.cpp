#include<bits/stdc++.h>
using namespace std;



// Given a binary array nums and an integer goal, return the 
// number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

// brute approach
int numSubarraysWithSum(vector<int>& nums, int goal) {
    // we can do this using the analogy of 
    // (no of subarrays with sum = 2) - (no of subarrays with sum = 1)
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i ; j < n; j++){
            sum = sum + nums[j];
            if(sum == goal){
                count++;
            }
        }
    }
    return count;
}



class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // we can do this using the analogy of
        // (max no. of subarrays with sum = 2) - (no of subarrays with sum = 1)
        return func(nums,goal) -func(nums,goal-1);
    }

private:
    int func(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.size();
        int count = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < n) {
            sum = sum + nums[right];
            while (sum > goal) {
                sum = sum - nums[left];
                left++;
            }
            // we are calculating sum <= goal 
            
            count = count + (right-left+1);
            right++;
        }
        return count;
    }
};