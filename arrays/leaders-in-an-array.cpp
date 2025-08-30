#include<bits/stdc++.h>
using namespace std;


// brute force - TC - O(n^2)
// vector <int> leadersInAnArray(vector<int>& nums){
//     vector <int> temp;
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         bool is_greater = true;
//         for(int j = i+1; j < n; j++){
//             if(nums[i] < nums[j]){
//                 is_greater = false;
//                 break;
//             }
//         }
//         if (is_greater) temp.push_back(nums[i]);
//     }
//     return temp;
// }

vector <int> leadersInAnArray(vector<int>& nums){
    int n = nums.size();
    vector <int> temp;
    int CurrMax = nums[n-1];

    temp.push_back(nums[n-1]);
    for(int i = n-2; i >= 0; i--){
        if(nums[i] > CurrMax){
            temp.push_back(nums[i]);
            CurrMax= nums[i];
        }
    }
    reverse(temp.begin(), temp.end());
    return temp;
}


int main(){
    vector<int> v1 = {10,22,12,3,0,6};

    vector <int> result = leadersInAnArray(v1);
    for(auto it: result){
        cout << it << " ";
    }
}