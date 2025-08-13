#include<bits/stdc++.h>
using namespace std;

// functional way - gives sum of first n numbers
int FunctionalSum(int n){
    if (n == 0) return 0;

    int sum = n + FunctionalSum(n-1);
    return sum;
}

// parameterized way - gives sum of first n numbers
void ParameterizedSum(int i, int sum){
    if (i < 1){
        cout << sum;
        return;
    }
    ParameterizedSum(i-1, sum + i);
}

int main(){
    int n;
    cout<< "Enter n: ";
    cin >> n;
    ParameterizedSum(n,0);
    int result = FunctionalSum(n);
    cout << endl<< "The sum of first "<< n << " natural numbers is: "<< result << endl; 

}