#include<bits/stdc++.h>
using namespace std;



// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length


// thought process , extremley navie appraoch 
// generate all substrings, and check like how many characters we can replace , if 
// it is less than allowed , we take the length of the subarrays otherwise break

// how will be check how many characters we can replcase??
// for a particular substring , we maintian a hash array , we calcualte the highest frequency and subtract
// it from total length, fro eg AABABBA , if we chhose AABAB , hash array wil say A= 3, B = 2
// changes possible length(5) - maxfreq(3) = 2 <= allowed changes , then take it's length ,  

// int characterReplacement(string s, int k){
//     int n = s.size();
//     int maxLength = 0;
//     for(int i = 0; i< n; i++){
//         int hash[26] = {0};
//         int maxfreq=0;
//         for(int j = i; j < n; j++){
//             hash[s[j] - 'A']++;
//             maxfreq =  max(maxfreq, hash[s[j] - 'A']);
//             int changes = (j-i+1) - maxfreq;
            
//             if (changes <= k){
//                 maxLength = max(maxLength, j-i+1);
//             }
//             else break;
//         }
//     }
//     return maxLength;
// }



// better approach
int characterReplacement(string s, int k){
    int n = s.size();
    int maxLength = 0;
    int left = 0; int maxFreq = 0; int right = 0;
    int hash[26]={0};

    while(right < n){
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);


        // if total changes exceed k , shrink
        while((right - left + 1 - maxFreq) > k){
            hash[s[left] - 'A']--;
            left++;
        }

        maxLength = max(maxLength, right-left+1);

        right++;

    }
    return maxLength;
}






int main(){
    string s = "AABABBA";
    int k = 1;
    int result = characterReplacement(s, k);
    cout << result;
}