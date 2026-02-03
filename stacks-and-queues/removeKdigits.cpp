#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if (k == num.size())
            return "0";

        for (char c : num) {
            while (!st.empty() && (k > 0) && c < st.top()) {
                st.pop();
                k--;
            }

            st.push(c);
        }
        // if k still left
        while (k > 0 && !st.empty()){
            st.pop();
            k--;
        }


        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());

            st.pop();
        }
        // trim initial zeroes
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }

        if (ans.empty()) return "0";

        reverse(ans.begin(), ans.end());
        return ans;

    }
};