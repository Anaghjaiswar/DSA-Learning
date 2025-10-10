// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


// Input: s = "the sky is blue"
// Output: "blue is sky the"
#include<bits/stdc++.h>
using namespace std;


// TC= O(n) && SC= O(n)
string reversedString(string s){
    vector<string> words;
    int n = s.size();
    string result;
    string word;
   
    for (int i = 0; i < n; i++){
        while(i<n && s[i]==' ') i++;

        word = "";
        while(i < n && s[i] != ' '){
            word += s[i];
            i++;
        }
        
        if(!word.empty()) words.push_back(word);
    }
    reverse(words.begin(), words.end());
    for(size_t i = 0; i < words.size(); i++){
        if(i > 0) result += ' ';
        result += words[i];
    }
    return result;
}




// Follow-up Optimization (In-place O(1) space)
// If you're up for a challenge, the LeetCode follow-up asks: Can you do it in-place with O(1) extra space? That would involve:

// Reversing the entire string

// Reversing each word individually

// Removing extra spaces in-place
string reversedString2ndpart(string s){
    string result;
    reverse(s.begin(),s.end());
    cout << s;


    return result;
}




int main(){
    string s = "the sky is blue";
    string result = reversedString2ndpart(s);
    cout << "reversed string is: "<< result;
}