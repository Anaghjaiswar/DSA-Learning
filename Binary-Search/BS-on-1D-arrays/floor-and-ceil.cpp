#include<bits/stdc++.h>
using namespace std;


// ceil is lower bound itself



int floor(vector<int> nums, int n , int target){
    int ans = -1;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low+high)/2;

        if (nums[mid] > target) high = mid -1;
        else {
            low = mid + 1;
            ans = nums[mid];
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {10,20,30,40,50};
    int target = 25;
    int result = floor(nums, nums.size(), target);
    cout << result;
}