#include <bits/stdc++.h>
using namespace std;

/*
Operands (A, B, 1, 2): Print them immediately to the output string.

( : Push it onto the stack.

) : Pop from the stack and print until you find (, then discard the (.

*Operators (+, -, , ^): Pop and print items from the stack that have higher or equal precedence than the current operator (except for ^ which is right-associative), then push the current operator.

End of String: Pop and print everything remaining in the stack.
*/


int priority(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1; // lowest for any other
}

string infixToPostfix(string s)
{
    string ans = "";
    stack<char> st;
    for (size_t i = 0; i < s.size(); i++)
    {
        // if it is operand
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); // to pop the opening bracket itself
        }
        else
        {
            while(!st.empty()){
                if (s[i] == '^')
                {
                    if (priority(s[i]) < priority(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }else break;
                }
                else
                {
                    if (priority(s[i]) <= priority(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }else break;
                }
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string s = "a^b^c";
    cout << "Postfix: " << infixToPostfix(s) << endl;
    return 0;
}
