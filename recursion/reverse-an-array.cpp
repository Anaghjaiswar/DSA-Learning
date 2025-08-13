#include <bits/stdc++.h>
using namespace std;


// void swap(int &l , int &r){
//     int temp;
//     temp = l;
//     l = r;
//     r = temp; 
// }

// array-reversal using 2 pointers
void reverseArray2(int a[], int l, int r){
    if (l >= r) return;
    
    swap(a[l], a[r]); // a built-in algorithm in c++
    reverseArray2(a,l+1, r-1);
}

// array-reversal using 1 pointer only
void reverseArray1(int a[], int i, int n){
    if (i >= (n/2) ) return;

    swap(a[i], a[n-i-1]);
    reverseArray1(a, i+1, n);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cout << "Enter element at position-"<<i+1<< ": ";
        cin >> a[i];
    }
    
    reverseArray1(a,0, n);

    // reverseArray2(a, 0, n-1);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

}