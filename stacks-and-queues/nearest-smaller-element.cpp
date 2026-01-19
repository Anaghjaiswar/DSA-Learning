#include<bits/stdc++.h>
using namespace std;


vector<int> nearestSmallerElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0 ; i < n; i++){
        int currEle = arr[i];

        while(!st.empty() && st.top() >= currEle){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(currEle);
    }
    return ans;
}
