#include<bits/stdc++.h>
using namespace std;


// TC = O(n) approach
vector<int> firstAndLastOccurence(vector<int>& nums, int target){
    int n = nums.size();
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++){
        if (nums[i] == target) {
            if (first == -1) first = i; //update only once
            last = i; // update everytime if matches target
        }
    }
    return {first, last};
}


// o(logn) approach
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return {-1, -1};

    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lb == n || nums[lb] != target) return {-1, -1}; // not found

    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return {lb, ub - 1};
}



 
int main(){
    vector<int> nums = {2,4,6,8,8,8,8,11,13};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout<< result[0] << " "<< result [1]; 
}