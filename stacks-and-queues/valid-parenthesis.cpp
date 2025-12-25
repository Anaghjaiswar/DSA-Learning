#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        bool isValid = false;
        for (char c : s) {

            // if opening brackets directly push
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
                isValid = false;
            }

            // if clsing brackets then check top , if same pop else return false
            if (c == ')') 
            {
                if (stk.size() != 0 && stk.top() == '(') {
                    stk.pop();
                    isValid = true;
                } 
                else return false;
            }

            else if (c == ']') {
                if (stk.size() != 0 && stk.top() == '[') {
                    stk.pop();
                    isValid = true;
                } else return false;
            }

            else if (c == '}') {
                if (stk.size() != 0 && stk.top() == '{') {
                    stk.pop();
                    isValid = true;
                } else return false;
            }
        }

        if (stk.size() != 0) return false;
        return isValid;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            else {
                // if no opening brackets yet directly return false
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                    return false;

            }
        }
        return st.empty();
    }
};