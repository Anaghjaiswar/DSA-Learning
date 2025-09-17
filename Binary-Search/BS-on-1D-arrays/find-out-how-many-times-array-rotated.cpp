#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int i = 0;
        for(; i<nums.size() ; i++){
            if(nums[i-1] > nums[i]) break;
        }

        // already sorted
        if (i == nums.size()) return 0;

        return i;
    }
};