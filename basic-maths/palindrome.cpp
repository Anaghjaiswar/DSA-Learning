class Solution {
public:
    bool isPalindrome(int x) {
        // no palindrome for negative numbers
        if (x < 0) return false;

        int n = x;
        long long revNumber = 0;
        while (x > 0){
            
            revNumber = (revNumber * 10) + (x%10);
            x = x / 10;

        }
        if (n==revNumber || n==0) return true;
        return false;
    }
};