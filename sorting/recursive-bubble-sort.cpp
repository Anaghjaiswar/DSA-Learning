#include <bits/stdc++.h>
using namespace std;

// Forward declaration
void helper(vector<int>& nums, int j);

vector<int> bubbleSort(vector<int>& nums) {
    helper(nums, nums.size());
    return nums;
}

void helper(vector<int>& nums, int j) {
    if (j <= 1) return; // base case

    bool didSwap = false;
    for (int i = 0; i < j - 1; i++) {
        if (nums[i] > nums[i+1]) {
            swap(nums[i], nums[i+1]);
            didSwap = true;
        }
    }

    if (!didSwap) return; // already sorted
    helper(nums, j - 1);  // recursive call
}

