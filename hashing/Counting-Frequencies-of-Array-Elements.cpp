// Counting Frequencies of Array Elements
// Given an array nums of size n which may contain duplicate elements, return a list of pairs where each pair contains 
// a unique element from the array and its frequency in the array.

// You may return the result in any order, but each element must appear exactly once in the output.
// Input: nums = [1, 2, 2, 1, 3]

// Output: [[1, 2], [2, 2], [3, 1]]

// Explanation:

// - 1 appears 2 times

// - 2 appears 2 times

// - 3 appears 1 time

// Order of output can vary.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        // Your code goes here
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        vector < vector <int> > result;

        for(auto &it: mpp){
            result.push_back({it.first, it.second});
        }

        return result;
    }
};