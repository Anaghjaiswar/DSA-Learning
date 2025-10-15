#include<bits/stdc++.h>
using namespace std;




int func(vector<int>& nums, int k){
    int left = 0;
    int right = 0;
    int oddCount = 0;
    int subarrayCount = 0;
    int n = nums.size();

    while(right < n){
        if(nums[right] % 2 == 1) {
            oddCount++;
            // subarrayCount++;
        }

        while(oddCount > k){
            if(nums[left] % 2 == 1){
                oddCount--;
            }
            left++;
                
        }
        subarrayCount += (right-left+ 1);
        right++;
    }



    return subarrayCount;

}

int numberOfSubarrays(vector<int>& nums, int k) {
    return func(nums,k) - func(nums,k-1);
}


int main(){
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    int result = numberOfSubarrays(nums,k);
    cout << result;
}