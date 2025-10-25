#include<bits/stdc++.h>
using namespace std;



// Given two strings s and t of lengths m and n respectively, 
// return the minimum window substring of s such that every 
// character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?



class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int m = s.size();
        int n = t.size();

        int left = 0;
        int right = 0;
        int count = 0;
        int minLen = INT_MAX;

        int startIndex = -1;

        int hash[256] = {0};
        for(int i = 0; i < n; i++) hash[t[i]]++;


        while(right < m){
            // Decrease the frequency in HASH ARRAY (can go neagtive if not present earlier )
            hash[s[right]]--; // we are consuming characters here 

            // if it was present earlier then only this loop will runn 
            if(hash[s[right]] >= 0) count++;
            
            // when we have all the needed chars in current window
            while(count == n){

                // Update the minimum window if current is smaller
                if(right-left+1 < minLen){
                    minLen = right -left + 1;
                    startIndex = left;
                }

                //Now, when we shrink the window from the left (left++), 
                // we’re removing a character from the current window. So we 
                // need to restore its count in the hash array—hence hash[s[left]]++.
                hash[s[left]]++; 

                // if something was previously zero means it was not in hash array 
                // and above operation make it 1 , then decrease counter 
                // it means we’ve removed a character that was required.
                // So the window is no longer valid—we’re missing a required character.
                // Therefore, we decrement count,

                if(hash[s[left]] > 0) count--;
                left++;
 
            }

            // expand window
            right++;


        }


        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};