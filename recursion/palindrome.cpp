#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, size_t i){
    if (i >= (s.size()/2)) return true;

    if (s[i] != s[s.size()-i-1]) return false;

    return isPalindrome(s, i+1);
}


int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    if(isPalindrome(s, 0)) cout << "String is palindrome";
    else cout << "String is not palindrome";

    return 0;
}