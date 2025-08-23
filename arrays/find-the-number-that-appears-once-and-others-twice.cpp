#include<bits/stdc++.h>
using namespace std;

// brute force appproach - O(n^2)
// int numberAppearingOnce(vector<int>& nums){
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         bool found = false;
//         for(int j = 0; j < n; j++){
//             if(i!=j && nums[i] == nums[j]){
//                 found = true;
//                 break;
//             }
//         }
//         if(!found) return nums[i];
//     }
//     return -1; // will not reach here 
// }


// int largestNumber(vector<int> arr){
//     int largest = arr[0];
//     int n = arr.size();
//     for(int i = 0; i< n; i++){
//         if(arr[i] > largest) largest = arr[i];
//     }
//     return largest;
// }

// better approach - TC - O(n+m) and SC  --> O(n)
// int numberAppearingOnce(vector<int>& nums){
//     int n = nums.size();

//     int largest = largestNumber(nums);
//     vector<int> hash(largest+1, 0);

//     // count frequencies
//     for(int i = 0 ; i < n; i++){
//         hash[nums[i]]++;
//     }

//     // see which appeared once
//     for(int i = 0 ; i <= largest; i++){
//         if(hash[i] == 1){
//             return i;
//         }
//     }

//     return -1;


// }


// // optimal approach - O(n) time complexity and O(1) space complexity
int numberAppearingOnce(vector<int>& nums){
    int result = 0;
    // 1^1 = 0
    // 0^1 = 1;
    // 0^0 = 0;


    for(auto it: nums){
        result ^= it;
    }

    // result= 1^1^2^3^3^4^4; -- > 0^2^0^0 --> 2

    return result;
}


int main(){
    vector <int> v1 = {1,1,2,3,3,4,4}; // 2
    int OnceAppearingNumber = numberAppearingOnce(v1);
    cout << "number which appeared once in the array is: "<< OnceAppearingNumber;
}