#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 1;
        int n = nums.size();
        for(;i < n; i++){
            if(nums[i-1] > nums[i]) break;
        }

        // if already sorted
        if (i == n) {
            return binary_search(nums, 0, n-1, target);
        }

        // check for pivot itself
        if(nums[i] == target ) return i;

        // Decide search half
        if(target > nums[i] && target <= nums[n-1]){
            return binary_search(nums, i+1, n-1, target);
        }
        else {
            return binary_search(nums, 0, i-1, target);
        }
    }
private:
    int binary_search(vector<int>& nums, int low, int high, int target){
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            if(target > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};