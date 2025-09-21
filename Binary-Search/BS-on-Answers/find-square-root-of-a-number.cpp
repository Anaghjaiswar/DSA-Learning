#include<bits/stdc++.h>
using namespace std;


// reurn the exact or floor value if square not is a decimal value.
long long squareRoot(int n){
    int low = 1;
    int high = n - 1;
    long long ans = 0;
    while (low <= high){
        int mid = low + (high - low)/2;

        if ((mid * mid) <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;

}


int main(){
    int n ;
    cout << "Enter n: "; 
    cin >> n;
    long long result = squareRoot(n);
    cout << "square root of " << n<< " is " << result << endl;
    return 0;
}