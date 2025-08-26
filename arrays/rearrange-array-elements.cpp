#include<bits/stdc++.h>
using namespace std;

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// brute force 
// void rearrangeArrayElements(vector <int> & nums){
//     int n = nums.size(); // always even
//     vector <int> positiveArray;
//     vector <int> negativeArray;
//     vector <int> tempArray;
    
//     // pushing all the negative and positive values in respective array in their preserved order
//     for(int i = 0; i < n; i++){
//         if(nums[i] > 0) positiveArray.push_back(nums[i]);
//         else negativeArray.push_back(nums[i]);
//     }

//     for(int i = 0; i < n/2; i++){
//         nums[2*i] = positiveArray[i];
//         nums[(2*i)+1] = negativeArray[i];
//     }
// }

// optimal approach 
void rearrangeArrayElements(vector <int> & nums){
    int n = nums.size();
    vector <int> ansArray(n);
    int posIndex=0, negIndex=1;
    for(int i = 0; i < n; i++){
        if(nums[i] < 0){
            ansArray[negIndex] = nums[i];
            negIndex += 2;
        }
        else{
            ansArray[posIndex] = nums[i];
            posIndex +=2;
        }
    }
    for(int i = 0; i< n; i++){
        nums[i]=ansArray[i];
    }
}

int main(){
    vector <int> v1 = {3,1,-2,-5,2,-4};
    rearrangeArrayElements(v1);
    for(auto it: v1){
        cout << it<< " ";
    }

}