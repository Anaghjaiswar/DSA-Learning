#include<bits/stdc++.h>
using namespace std;

// brute force approach
void MoveAllZeroesToTheEndOfTheArray(vector<int>& arr, int n){
    vector<int> temp;
    // Collect non-zero elements
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    // Copy non-zero elements back to arr
    int i = 0;
    for(; i < temp.size(); i++){
        arr[i] = temp[i];
    }
    // Fill the rest with zeros
    for(; i < n; i++){
        arr[i] = 0;
    }
}

// optimal approach
void moveZeroes(vector<int>& nums) {
        int j = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;

        for(int i = j+1; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }

    }
int main(){
    vector <int> v1 = {1,0,2,3,2,0,0,4,5,1};
    int n = v1.size();

    MoveAllZeroesToTheEndOfTheArray(v1, n);
    for(const auto it: v1){
        cout << it<< " ";
    }

}