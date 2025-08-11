// You are given an integer n. You need to check if the number is prime or not. 
// Return true if it is a prime number, otherwise return false.
// A prime number is a number which has only 2 factors -  1 and itself.
#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    int count = 0 ;

    // we will only check till sqrt of n bcz we get all factors within that limit
    for (int i = 1; i*i <= n ; i++){
        if(n % i == 0){
            count++;
            if((n/i) != i){
                count++;
            }
        }
    }
    if (count == 2) return true;
    return false;
}

int main(){
    int n;
    cout << "to check prime number enter n: ";
    cin>>n;
    if(isPrime(n)){
        cout << n << " is prime";
    }
    else{
        cout << n << " is not prime";
    }
}