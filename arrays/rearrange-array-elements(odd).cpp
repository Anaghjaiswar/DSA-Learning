#include<bits/stdc++.h>
using namespace std;

void rearrangeArrayElementsWithOddNoOfElements(vector<int>& nums){
    int n = nums.size();
    vector <int> posArray;
    vector <int> negArray;

    for(int i = 0; i < n ; i++){
        if(nums[i] > 0 ) posArray.push_back(nums[i]);
        else negArray.push_back(nums[i]);
    }

    if( negArray.size() > posArray.size()){
        for(int i = 0; i < posArray.size(); i++){
            nums[2*i] = posArray[i];
            nums[(2*i)+1]=negArray[i];
        }
        for(int i = 2*posArray.size(); i < n; i++){
            nums[i] = negArray[i-posArray.size()];
        }
    }
    if( posArray.size() > negArray.size()){
        for(int i = 0; i < negArray.size(); i++){
            nums[2*i] = posArray[i];
            nums[(2*i)+1]=negArray[i];
        }
        for(int i = 2*negArray.size(); i < n; i++){
            nums[i] = posArray[i-negArray.size()];
        }
    }


 
}

int main(){
    vector <int> v1 = {2,1,-4,-5,-1,-2,8,-7,-9};
    rearrangeArrayElementsWithOddNoOfElements(v1);
    for(auto it: v1){
        cout << it << " ";
    }
}