#include<bits/stdc++.h>
using namespace std;
// brute tc- O(n^2) and SC -> O(1)
// int maximumPossibleSumOfSubarray(vector <int>& arr){
//     int maxSum = INT_MIN;
//     int n = arr.size();
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j< n; j++){
//             sum = sum + arr[j];
//             maxSum = max(sum, maxSum);
//         }
//     }
//     return maxSum;
// }

// optimal - kadane's algorithm (don't carry negative sum forward)
int maximumPossibleSumOfSubarray(vector <int>& arr){
        long long maxSum = arr[0];
        int ansStart = -1;
        int ansEnd = -1;
        int start;
        long long sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
           
            sum = sum + arr[i];

            if(sum > maxSum){
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }

            if(sum < 0){
                sum = 0;
                start = i + 1;
            }
        }


        return (int)maxSum;
    }



int main(){
    vector<int > v1 = {-2,-3,4,-1,-2,1,5,-3};
    int result = maximumPossibleSumOfSubarray(v1);
    cout << "maximum subarray sum is: "<<result;
}