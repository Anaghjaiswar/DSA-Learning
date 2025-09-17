#include <bits/stdc++.h>
using namespace std;

// TC - O(N) - brute
int singleElementInSortedArray(vector<int>& nums){
    int n = nums.size();
    if(n==1) return nums[0];

    for(int i = 0; i < n; i++){
        if (i == 0){
            if (nums[i] != nums[i+1]) return nums[i];
        }
        else if(i == n-1){
            if (nums[i] != nums[i-1]) return nums[i];
        }
        else{
            if ((nums[i] != nums[i-1]) && (nums[i] != nums[i+1])) return nums [i];
        }
    }
    return -1;
}


// bs way
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n-2;
        int mid = -1;

        while(low <= high){
            mid = (low + high)/2;

            if ((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1])) {
                return nums[mid];
            }

            // ON RIGHT HALF - eliminate left half
            if (
                // standing at odd checking for even 
                ((mid % 2 == 1) && (nums[mid-1] == nums[mid])) 
                || 
                // standing at even and checking for odd
                ((mid % 2 == 0) && (nums[mid] == nums[mid+1]))
            ){
                low = mid + 1;
            }
            // ON LEFT HALF - eliminate right half
            else{
                high = mid - 1;
            }

        }
        return -1;

        
       
    }
};


int main(){
    vector<int> v1 = {1,1,2,2,3,3,4,5,5,6,6};
    int result = singleElementInSortedArray(v1);
    cout << result;
}