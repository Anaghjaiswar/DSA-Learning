#include<bits/stdc++.h>
using namespace std;

// there are generally 4 types of patterns in this problem
// 1. Constant problem --- Constant window (fixed-length subarray using 2 pointers).

// like for eg consider an array with +ve's and -ve's you have to find the maximum sum which you can obtain by picking 4 elements consecutively.
// so first calculate the first 4 values sum then just you need to increase pointers and remoe last value sum and add another value sum 


int maxSum(vector<int> nums, int k){
    int n = nums.size();
    if (n < k) return -1; 


    int l = 0;
    int r = k-1;
    int sum = 0;

    for(int i = l; i <= r; i++){
        sum += nums[i];
    }
    

    int max_sum = sum;
    while(r+1 < n){

        sum = sum - nums[l];
        l++;
        r++;
        sum = sum + nums[r];

        max_sum = max(sum, max_sum);
        
    }
    return max_sum;
}

// Pattern 2 — Variable-length window (sum ≤ target)

// Goal: Find max length subarray whose sum ≤ target

// first is brute appraoch like generate all possible subarrays and then write condition according to your logic

int maxSubarraySum(vector<int>nums, int maxValue){
    int max_length = 0;
    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for (int j = i; j < nums.size(); j++){
            sum = sum + nums[j];

            if(sum <= maxValue) max_length = max(max_length, j-i+1);
            else if(sum > maxValue) break; 
        }
    }
    return max_length;
}



// better approach

// initialize sum to zero 
// now there are 2 concepts

// 1- expand -- right part of window
// 2- shrink -- left part of Window

// current window should go to your sum 
// let's say array = [2,5,1,10,10], k = 14
// sum = 2 
// expand
// r move forward  sum = 7 (sum <k)
// r move sum = 8 (sum < k)
// r move sum = 18 (sum > k)
// shrink from left till you get in a valid condition

// take out 2 , sum = 16 , l move forward (sum > k)
// take out 5 , sum = 11 , l move forward (sum < k)

// now again expand 
// r move forward , sum = 21 , (sum < k) 
// 


// l = 0, r= 0, sum = 0, max_len = 0

// while(r<n){
    // sum = sum + arr[r] // new elemnt adding to the window 

    // if(sum > k) sum = sum - arr[l] and then l++;

    // if(sum <= k) max_len = max(max_len, r-l+1); // in case asking fro the subarray store l and r here 

    // r++;
// }

// print (max_len)
// TC -- O(2N) ~ O(N), SC = O(1)
int maxsubarraysum(vector<int>& nums, int k){
    int n = nums.size();

    int l = 0;
    int r = 0;
    int sum = 0;
    int max_length = 0;

    while(r < n){
        sum = sum + nums[r];
        while(sum > k && l <=r) {
            sum = sum - nums[l];
            l++;
        }

        if(sum <= k){
            max_length = max(max_length, r-l+1);
        }
        r++;
    }
    return max_length;

}


// optimized way
// what if we say we don't have to shrink it all the way
// like instead of shrinking it all together just check do 1 shrink ,  

// like if got  3 then why reduce it , however this method is not useful if we want to get the subarray is_partitioned

int maxsubarraysum(vector<int>& nums, int k){
    int n = nums.size();

    int l = 0;
    int r = 0;
    int sum = 0;
    int max_length = 0;

    while(r < n){
        sum = sum + nums[r];
        if(sum > k && l <=r) {
            sum = sum - nums[l];
            l++;
        }

        if(sum <= k){
            max_length = max(max_length, r-l+1);
        }
        r++;
    }
    return max_length;

}

// ~~~~~~~~~~~~~~~~~~~~~~~~~
// 3rd pattern
// ~~~~~~~~~~~~~~~~~~~~~~~~~

// no. of subarrays where some condition
// this problem will be solved using pattern 2
// hey can you figure out the no. of subarrays with sum == k 
// if need the number of subarrays and there is a constnt conditional
// it is difficult to find when the shrink or expand 

// we can follow the pattern like this (x-y)
// (no. of subarrays with sum <= k) - (no. of subarray with sum <= k-1)



// ~~~~~~~~~~~~~~~~~~~~~~~~~
// 4th pattern - shortest mini. window with some condition k 
// ~~~~~~~~~~~~~~~~~~~~~~~~~






















// Pattern name: Complement Window / Reverse Window
// Use-case: When problem asks to take k items from ends, or skip smallest continuous section.
// Base pattern: Pattern 1 (fixed-size window).