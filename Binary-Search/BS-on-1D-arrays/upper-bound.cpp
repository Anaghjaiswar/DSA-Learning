#include<bits/stdc++.h>
using namespace std;

// TC = O(log base 2 (n))
int upper_bound(vector<int> nums, int target, int n ){
    int low = 0;
    int high = n-1;
    int ans = n;

    while (low <= high){
        int mid = low + (high - low)/2;

        if (nums[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else low = mid +1;
    }
    return ans;
}





int main(){
    vector <int> v1 = {1,2,3,3,7,8,9,9,9,11};
    int target = 9;
    int result = upper_bound(v1, target, v1.size());
    cout << result;
}