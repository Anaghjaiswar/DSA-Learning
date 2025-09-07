#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithXorK(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int prexor = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        prexor ^= nums[i];

        int needed = k ^ prexor;

        count = count + mpp[needed];
        mpp[prexor] += 1;
    }
    return count;
}


int main(){
    vector<int> v1 = {4,2,2,6,4};
    int k = 6;
    int count = countSubarraysWithXorK(v1, k);
    cout<< count;
}