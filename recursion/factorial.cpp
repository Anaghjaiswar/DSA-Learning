#include <bits/stdc++.h>
using namespace std;

int Factorial(int n){
    if (n == 0) return 1;

    return n * Factorial(n-1);
}


int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int result = Factorial(n);
    cout << "the factorial of "<< n << " is "<< result;
}