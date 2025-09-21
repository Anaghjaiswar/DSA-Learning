#include<bits/stdc++.h>
using namespace std;


long long power(int base, int exp, int m) {
    long long ans = 1;
    for (int i = 1; i <= exp; i++) {
        ans *= base;
        if (ans > m) return -1; // overflow ya limit se bada
    }
    if (ans == m) return 1;  // exact match
    return 0;                // smaller than m
}

int nthRoot(int n, int m){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid = low + (high - low)/2;
        int ans = power(mid,n, m);
        if (ans == 1) return mid;  // mid^n == m
        else if (ans == 0) low = mid + 1; // mid^n < m
        else high = mid - 1; // mid^n > m
    }
    return -1;
}

 
int main(){
    int n = 3;
    int m = 27;
    long long result = nthRoot(n,m);
    cout << "nth root of " << m << " is " << result << endl;
    return 0;
}