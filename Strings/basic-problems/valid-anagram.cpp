#include<bits/stdc++.h>
using namespace std;
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?










class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int hashS[26]= {0};
        int hashT[26] = {0};

        for(int i = 0; i < s.size(); i++) hashS[s[i] - 'a']++;
        for(int i = 0; i < t.size(); i++) hashT[t[i] - 'a']++;

        for(int i = 0; i < 26; i++){
            if(hashS[i] != hashT[i]) return false;
        }
        return true;

        
    }
};