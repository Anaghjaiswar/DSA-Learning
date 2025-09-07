#include<bits/stdc++.h>
using namespace std;


// better approach - hashing
vector <int> majorityElementsNby3times(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> mpp; 
    vector<int> temp;

    // We need elements that occur strictly more than n/3 times.
    // So the minimum required frequency is (n/3) + 1.
    int minimum = (n/3) + 1;

    for(int i = 0; i < n; i++){
        mpp[nums[i]]++;

        // Add the element as soon as it reaches the threshold.
        if (mpp[nums[i]] == minimum){
            temp.push_back(nums[i]);
        }
    }

    // No need for a second pass over the map, since we already push 
    // elements once they reach the required frequency.
    // for(auto it: mpp){
    //     if( it.second > (n/3)){
    //         temp.push_back(it.first);
    //     }
    // }

    return temp;
}


int main(){
    vector <int> v1 = {1,1,1,3,3,2,2,2};
    vector <int> result = majorityElementsNby3times(v1);
    for(auto it : result){
        cout << it << " ";
    }
}