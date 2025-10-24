#include<bits/stdc++.h>
using namespace std;


// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
 

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.







class Solution {
public:
    int numberOfSubstrings(string s) {
        return func(s,3) - func(s,2);
    }
private:
    int func(string& s, int n){
        int k = s.size();
        int right = 0;
        int left = 0;
        int totalLength= 0;
         unordered_map<char, int> mpp;
        while(right < k){
            mpp[s[right]]++;

           while(mpp.size() > n){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }
                left++;
           }

            totalLength += right - left + 1;
            right++;
        }
        return totalLength;
    }
};




// another solution (need to see this )


class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0};  // Frequency array for 'a', 'b', 'c'
        int left = 0, res = 0;
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;  // Increase frequency of current character
            
            // When all characters a, b, and c are present in the window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.size() - right;  // Add all valid substrings
                count[s[left] - 'a']--;   // Shrink the window from the left
                left++;
            }
        }
        return res;
    }
};