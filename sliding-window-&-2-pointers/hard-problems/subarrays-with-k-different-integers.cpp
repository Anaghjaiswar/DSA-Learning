#include<bits/stdc++.h>
using namespace std;


int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

int atMost(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;
    int left = 0;
    int right = 0;
    int count = 0;
    int n = nums.size();
    while (right < n) {
        mpp[nums[right]]++;

        while (mpp.size() > k) {
            mpp[nums[left]]--;

            if (mpp[nums[left]] == 0)
                mpp.erase(nums[left]);

            left++;
        }

        count = count + (right - left + 1);
        right++;
    }
    return count;
}


int main(){
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    int result = subarraysWithKDistinct(nums,k);
    cout << result;
}