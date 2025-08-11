// You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) 
// of the two given numbers. 
// Return the GCD of the two numbers.
// The Greatest Common Divisor (GCD) of two integers is the largest positive integer 
// that divides both of the integers.


#include <bits/stdc++.h>
using namespace std;


// euclidean algorithm
int GCD(int n1,int n2) {

    if (n1 == 0 && n2 == 0) return 0; // undefined case

    // if one of them is zero the other will be definitely the gcd
    if (n1 == 0) return n2; 
    if (n2 == 0) return n1;

    // looping until one of them becomes zero 
    // always we will be dividing greater number by smaller number until one becomes zero
    while(n1 > 0 && n2 > 0){
        if (n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }

    if (n1 == 0) return n2;
    else return n1;
}


int main(){
    int n1, n2;
    cout << "Enter n1: ";
    cin >> n1;
    cout << endl << "Enter n2: ";
    cin >> n2;

    int result = GCD(n1, n2);
    cout << "GCD or HCF of n1 and n2 is: "<< result;
}