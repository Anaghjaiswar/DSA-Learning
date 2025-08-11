// You are given an integer n. You need to find all the divisors of n. 
// Return all the divisors of n as an array or list in a sorted order.
// A number which completely divides another number is called it's divisor.


# include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n) {
    vector <int> v;
    // o(sqrt n)
    for (int i = 1; i* i <=(n) ; i++){
        if (n % i == 0) {
            v.emplace_back(i); // pushing the first factor
            // now second factor

            // equality check of whether they are equal or not otherwise 2 times print
            if((n/i) != i) {
                v.emplace_back(n/i);
            }
        }
    }
    // o(nlogn) n - no of factors
    sort(v.begin(), v.end()); // ensure sorted order
    return v;
}

int main(){
    int n;
    cout << "enter n:";
    cin >> n;
    vector <int> result = divisors(n);

    // o(n)
    for (auto it : result ) cout << it << " ";
}

