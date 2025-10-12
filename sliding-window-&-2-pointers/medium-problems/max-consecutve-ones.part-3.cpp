#include <bits/stdc++.h>
using namespace std;


// this problem can be converted to a longest subarray with atmost k zeros;
// and then we can calculate it's length to cehck for the maximum consecutive one's 
// because we can atleast flip k zeroes

// brute approach
// int longestOnes(vector<int>& nums, int k){
//     int n = nums.size();
//     int max_length = 0;
    
//     for(int i = 0; i < n; i++){
        
//         int countZero = 0;
//         for(int j = i; j < n; j++){
//             if(nums[j] == 0) countZero++;

//             if(countZero <= k) {
//                 int length = j-i+1;
//                 max_length = max(max_length, length);
//             }
//             else break; // if zeroes exceed k
//         }
//     }
//     return max_length;
// }


// optimal appraoch
// int longestOnes(vector<int>& nums, int k){
//     int n = nums.size();
//     int left = 0;
//     int right = 0;
//     int maxLength = 0;
//     int zeroCount = 0;

//     while(right < n){

//         // agar zero hai to right ko aage badao aur zero ka count increase karo
//         if(nums[right] == 0) zeroCount++;


//         // agar zero ka count k se zyada aata ahi matlab condition tu rahi hai , to shrink karke condition satisfy akro 
//         // left ko dekho agar woh zero hai toh ek zero count kam karo aur left pointer aage badahao aur agar 1 hai toh aise hi aage badaa dho 
//         while(zeroCount > k){
//             if(nums[left] == 0) zeroCount--;
//             left++;
//         }

//         // iske baad zero count apne aap sahi honge 
//         // max length update karsakte ahia kyuki is waqt jo window hai usme zyada se zyada k hi zeroes honge jo ki flip ho sakte hai 
        

//         maxLength = max(right-left+1, maxLength);
//         right++;
        
//     }
//     return maxLength;

// }


//bettter tha
int longestOnes(vector<int>& nums, int k){
    int n = nums.size();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int zeroCount = 0;

    while(right < n){
        if(nums[right] == 0) zeroCount++;

        if(zeroCount > k){
            if(nums[left] == 0) zeroCount--;
            left++;
        }

        if(zeroCount <= k){

            maxLength = max(right-left+1, maxLength);
        }
        
        right++;
    }
    return maxLength;

}

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int result = longestOnes(nums, k);
    cout << result;

}