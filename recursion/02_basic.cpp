// print from 1 to n 
// print from n to 1

#include<bits/stdc++.h>
using namespace std;

// normal linear printing from 1 to n
void f(int i,int n){
    if (i > n) return ;

    cout << i << " ";
    f(i+1, n);
}
// normal linear printing from n to 1
void revF(int n){
    if(n < 1) return;

    cout << n << " ";
    revF(n-1);
}

// printing from 1 to n (using backtracing i.e. not allowed to use +1)
void backF(int i, int n){
    if (i<1) return;

    backF(i-1,n);
    cout << i <<" ";
}

// printing from n to 1(using backtracing i.e not allowed to use -1)
void BackRevF(int i, int n){
    if (i>n) return;

    BackRevF(i+1, n);
    cout << i << " ";
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Printing from 1 to n linearly: ";
    f(1,n);
    cout << endl << "Printing from n to 1 linearly: ";
    revF(n);
    cout << endl<< "Printing from 1 to n by backtracing: ";
    backF(n,n);
    cout << endl << "printing from n to 1 by backtracing: ";
    BackRevF(1,n);

}
