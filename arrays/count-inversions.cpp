#include<bits/stdc++.h>
using namespace std;


// brute force - O(n^2)
// int countInversions(vector<int>& nums){
//     int count = 0;
//     int n =  nums.size();

//     for(int i = 0; i < n; i++){
//         for (int j = i+1; j < n; j++){
//             if(nums[i] > nums[j]) count++;
//         }
//     }
//     return count;
// }

// optimal approach



int merge_sort(vector<int> v1, int low, int high){
// merge sort se implement karlo
}


int main(){
    vector <int> v1 = {1,2,4,3,5};
    int low = 0;
    int high = v1.size() - 1;
    int result = merge_sort(v1, low, high);
    cout << result;
}