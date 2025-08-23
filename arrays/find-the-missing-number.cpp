// Given an array nums containing n distinct numbers in the range [0, n], return
// the only number in the range that is missing from the array.

// Input: nums = [9,6,4,2,3,5,7,0,1]

// Output: 8

// Explanation:

// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

#include<bits/stdc++.h>
using namespace std;


// brute force approach - time complexity O(n^2)
// int missingNumber(vector<int>& arr){
//     for(size_t i = 0; i <= arr.size(); i++){
//         bool found = false;
//         for(size_t j = 0; j < arr.size(); j++){
//             if(i == static_cast<size_t>(arr[j])){
//                 found = true;
//                 break;
//             }
//         }
//         if(!found) return i;
//     }
//     return -1;  // ideally it should never reach here
// }

// a better approach - is hashing
int missingNumberByHashing(vector<int> arr){
    int n = arr.size();
    vector<int> hash(n + 1, 0);

    for(size_t i = 0 ; i < arr.size(); i++){
        hash[arr[i]] = hash[arr[i]]+1;
    }

    for(size_t i = 0; i < hash.size(); i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1;
}


// optimal approach (using sum approach)
int missingNumberBySumApproach(vector<int>& arr){
    int n = arr.size();

    // sum of first n natural numbers
    int sum1 = (n*(n+1))/2; 

    int sum2 = 0;

    // taking sum of all numbers in the original array
    for(size_t i = 0; i < arr.size(); i++){
        sum2=sum2+arr[i];
    }

    // difference of sum will give us the missing number
    return sum1-sum2;
}

int main(){
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    vector <int> v1; // [0,3,4,5,2,7,1,8,9]
    cout << "Enter elements: ";
    for(int i= 0; i < n ; i++) {
        int value;
        cin >> value;
        v1.push_back(value);
    }
    int MissingNumber = missingNumberBySumApproach(v1);
    cout << "missing number is : "<< MissingNumber;
}