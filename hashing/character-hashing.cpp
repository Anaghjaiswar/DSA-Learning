#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<< "Enter String: ";
    cin >> s;

    // precompute
    int hash[26]={0};
    for(size_t i = 0 ; i < s.size(); i++){
        hash[s[i]-'a']++;
    }

    int q;
    cout << "Enter queries: ";
    cin >> q;

    while(q--){
        char c;
        cout << "enter alphabhet to be searched: ";
        cin >> c;


        // fetch

        cout << c << " appeared "<< hash[c-'a']<< " times"<< endl;
    }
}