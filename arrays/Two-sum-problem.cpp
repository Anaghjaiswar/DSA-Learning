#include<bits/stdc++.h>
using namespace std;

// // brute force  
// bool doesTwoNumbersWithSumEqualsTargetExist(vector<int> &v1, int target){
//     int n = v1.size();
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i+1; j < n; j++){
//             sum = v1[i] + v1[j];
//             if (sum == target) return true;
//             sum = 0;
//         }
//     }
//     return false;
// }

// by hashing
// bool doesTwoNumbersWithSumEqualsTargetExist(vector<int> &v1, int target){
//     unordered_map<int , int> mpp;
//     int n = v1.size();
//     int needed = 0;
//     for(int i = 0; i < n; i++){
//         needed = target - v1[i];

//         if(mpp.find(needed) != mpp.end()){
//             return true;
//         }
//         mpp[v1[i]] = i;
//     }
//     return false;
// }

// optimal approach
bool doesTwoNumbersWithSumEqualsTargetExist(vector<int> &v1, int target){
    int left =0 ;
    int n = v1.size();
    int right = n -1 ;
    int sum = 0;
    sort(v1.begin(), v1.end());
    while(left < right){
        sum = v1[left] + v1[right];
        if(sum == target) return true;
        else if( sum > target) right--;
        else left++;
    }
    return false;

}

int main(){
    vector <int> v1 = {2,6,5,8,11};
    int target = 15;
    if(doesTwoNumbersWithSumEqualsTargetExist(v1, target)) cout << "exists";
    else cout << "does not exist";

    
}