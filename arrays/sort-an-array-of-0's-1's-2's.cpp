#include<bits/stdc++.h>
using namespace std;


// brute - merge sort

// better
// void sortArrayOfZeroesOnesTwos(vector<int>& nums){
//     int n = nums.size();
//     int CountZeroes = 0;
//     int CountOnes = 0;
//     int CountTwos = 0;
//     for(int i = 0; i < n; i++){
//         if(nums[i] == 0) CountZeroes++;
//         else if(nums[i] == 1) CountOnes++;
//         else CountTwos++;
//     }
//         int i = 0;
//         while(CountZeroes > 0 && i < n){
//             nums[i] = 0;
//             CountZeroes--;
//             i++;
//         }
//         while(CountOnes > 0 && i < n){
//             nums[i] = 1;
//             CountOnes--;
//             i++;
//         }
//         while(CountTwos > 0 && i < n){
//             nums[i] = 2;
//             CountTwos--;
//             i++;
//         }
// }

// optimal 
void sortArrayOfZeroesOnesTwos(vector<int>& nums) {
    // dutch national flag algorithm
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        else if (nums[mid] == 1) mid ++;
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector <int> v1 = {0,1,2,0,1,2,1,2,0,0,0,1};

    sortArrayOfZeroesOnesTwos(v1);
    for (auto it: v1){
        cout << it << " ";
    }
}