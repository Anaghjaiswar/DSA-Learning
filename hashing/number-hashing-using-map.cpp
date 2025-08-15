#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "enter array size: ";
    cin >> n;
    int a[n];
    cout << "enter array elements: ";
    for(int i=0; i<n;i++) cin >> a[i];

    // precompute
    map <int, int> mpp;

    for(int i=0; i<n; i++){
        mpp[a[i]]++;
    }



    int q; 
    cout << "How many queries you want: ";
    cin >> q;
    while(q--){
        int number;
        cout << "Enter number to be searched: ";
        cin >> number;


        // fetch
       cout << number << " appeared " << mpp[number] << " times" << endl;
    }

}