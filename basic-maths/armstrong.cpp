#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isArmstrong(int n) {
        if (n < 0) return false; // Armstrong numbers are non-negative
        if (n == 0) return true; // 0 is an Armstrong number

        int original = n;
        int count = (int) (log10(n) + 1);
        int sum = 0;

        while(n>0){
            int last_digit = n % 10;
            int power_var = 1;
            
            // taking the power to the count of the individual digit
            for (int i = 0; i < count ; i++){
                power_var = power_var * last_digit;
            }
            // adding it to sum variable 
            sum = sum + power_var;
            n = n/10;
        }

        return (sum == original) ;

    }
};