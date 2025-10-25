
#include<bits/stdc++.h>
using namespace std;

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
 

// Constraints:

// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n == 1 && s == goal) return true;  

        for(int i = 0; i < n; i++){
            string result = rightRotate(s, i);
            // cout << result<< endl;
            if(result == goal) return true;
        }
        return false;


    }
private:
    string rightRotate(string s, int d){

        if (d == 0) return s; 
        d = d % s.size();

        reverse(s.end()-d, s.end());
        reverse(s.begin(), s.end()-d);
        reverse(s.begin(), s.end());

        return s;
    }
};