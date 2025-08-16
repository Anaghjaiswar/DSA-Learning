#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
       helper(nums, 1);
       return nums;
    }


private:
    void helper(vector<int>& nums, size_t i){
        if (i >= nums.size()) return;

        for (int j = i; j > 0; j--){
            if (nums[j - 1] > nums[j]){
                swap(nums[j - 1], nums[j]);  // swaps
            } else {
                break; // already in order, no need to check further
            }
        }

        helper(nums, i+1);

    }
};

