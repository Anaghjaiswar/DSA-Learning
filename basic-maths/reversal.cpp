
#include <bits/stdc++.h>
class Solution {
public:
    int reverse(int n) {
        long long num = n;   // store in bigger type
        bool is_negative = false;

        if (num < 0) {
            is_negative = true;
            num = -num; // safe now because num is long long
        }

        long long rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }

        if (is_negative) rev = -rev;

        if (rev < INT_MIN || rev > INT_MAX) return 0; // overflow check
        return (int)rev;
    }
};
