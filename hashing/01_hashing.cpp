#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "enter array size: ";
    cin >> n;
    int a[n];
    cout << "enter array elements: ";
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    // precompute
    int hash[13] = {0};
    for(int i = 0; i<n ; i ++){
        hash[a[i]] += 1;
    }

    int q;
    cout << "How many queries you want: ";
    cin >> q;

    while(q--){
        int number;
        cout << "Enter number to be searched: ";
        cin >> number;
        cout << number << " appeared " << hash[number] << " times" << endl;
    }

    return 0;
}