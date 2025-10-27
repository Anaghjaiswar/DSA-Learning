#include<bits/stdc++.h>
using namespace std;
// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:

// Input: s = "aabcbaa"
// Output: 17
 

// Constraints:

// 1 <= s.length <= 500
// s consists of only lowercase English letters.


// brute force logic - O(n^3)

int beautySum(string s) {
    int n = s.size();
    int sum = 0;
    for(int i = 0; i< n; i++){
        int hash[26] = {0};
        for(int j = i; j< n; j++){
            hash[s[j] - 'a']++;
            int maxEle = *max_element(hash,hash + 26);
            // cout << "maxele: "<< maxEle << endl;
            int minEle = INT_MAX;
            
            for(int k = 0; k < 26; k++){
                if(hash[k] > 0) minEle = min(minEle, hash[k]);
            }

            sum = sum + (maxEle-minEle);
            // cout << "sum :" << sum << endl;

        }
    }
    return sum;
}



// better readable understandable code
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i< n; i++){
            vector<int> hash(26,0);
            for(int j = i; j< n; j++){
                hash[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for (int f: hash){
                    if(f > 0){
                        mini = min(mini, f);
                        maxi= max(maxi, f);
                    }
                }
                

                sum = sum + (maxi-mini);

            }
        }
        return sum;
    }
};