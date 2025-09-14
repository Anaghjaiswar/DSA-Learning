// a[i] > 2(a[j])
#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums){
    int count = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j< n; j++){
            if(nums[i] > 2*nums[j]){
                count++;
            }
        }
    }
    return count;

}


int main(){
    vector<int>v1 = {40,25,19,12,9,6,2};
    int result = countPairs(v1);  //only the one that are a[i] > 2(a[j])

    cout << result;

}