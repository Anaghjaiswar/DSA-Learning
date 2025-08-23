#include<bits/stdc++.h>
using namespace std;

// TC = O(n^3) and SC = O(1)
// int longestSubarraywithSumKpositives(vector<int>& v1, int K){
//     int longestLength = 0;
//     int n = v1.size();
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j < n; j++){
//             sum += v1[j];
        
//             if (sum == K) {
//                 longestLength = max(longestLength, j-i+1);
//             }
//         }
//     }
//     return longestLength;
// }

// int longestSubarraywithSumKpositives(vector<int>& a, int k){
//     int n = a.size(); // size of the array.

//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < n; i++) {
//         //calculate the prefix sum till index i:
//         sum += a[i];

//         // if the sum = k, update the maxLen:
//         if (sum == k) {
//             maxLen = max(maxLen, i + 1);
//         }

//         // calculate the sum of remaining part i.e. x-k:
//         long long rem = sum - k;

//         //Calculate the length and update maxLen:
//         if (preSumMap.find(rem) != preSumMap.end()) {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }

//         //Finally, update the map checking the conditions:
//         if (preSumMap.find(sum) == preSumMap.end()) {
//             preSumMap[sum] = i;
//         }
//     }

//     return maxLen;
// }

int longestSubarraywithSumKpositives(vector<int> &a, int k){
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];
    int maxlen = 0;



    for(int i = 0; i < n; i++){

        // while subarray exists and if sum > k we will decrease 1 from left till it sum is less than or equal to 6
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }

        if (sum == k) maxlen = max(maxlen, right - left +1);

        // otherwise simply increase right pointer and add it to sum 
        right++;
        // safety check
        if(right < n){
            sum += a[right];
        }

    }
    return maxlen;
}


int main(){
    vector<int> v1 = {1,2,3,1,1,1,1,4,2,3};
    int k = 6;

    int result = longestSubarraywithSumKpositives(v1, k);
    cout << result;
}
