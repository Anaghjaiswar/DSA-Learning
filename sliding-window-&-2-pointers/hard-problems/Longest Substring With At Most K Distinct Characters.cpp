// Given a string s and an integer k.Find the length of the longest 
// substring with at most k distinct characters
#include<bits/stdc++.h>
using namespace std;

// test case
// Input : s = "aababbcaacc" , k = 2

// Output : 6

// Explanation : The longest substring with at most two distinct characters is "aababb".

// The length of the string 6.

int kDistinctChar(string &s, int k){
    int n = s.size();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    unordered_map<char , int> mpp;

    while(right < n){
        mpp[s[right]]++;

        
        if(mpp.size() > k){ 
            mpp[s[left]]--;

            if(mpp[s[left]] == 0){
                mpp.erase(s[left]);
            }
            left++;
        }

        if (mpp.size() <= k){
            // cout << mpp.size();
            int length = right - left + 1;
            // cout << length;
            maxLength=max(length, maxLength);
        }

        right++;
    }
    return maxLength;
}




int main(){
    string s = "aababbcaacc";
    int k = 2;
    int result = kDistinctChar(s,k);
    cout << result;

}