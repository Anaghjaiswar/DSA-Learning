#include<bits/stdc++.h>
using namespace std;


vector<int> previousSmallerElement(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i< n; i++){
        int currEle = arr[i];

        while(!st.empty() && arr[st.top()] >= currEle){
            st.pop();
        }

        ans[i] = st.empty()  ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        int currEle = arr[i];

        while(!st.empty() && arr[st.top()] >= currEle){
            st.pop();
        }

        ans[i] = st.empty() ? n : st.top(); // If no smaller bar exists on the right,The boundary is n, not -1.
        st.push(i);
    }

    return ans;
}


int largestRectangleInAHistogram(vector<int>& arr){
    vector<int> pse = previousSmallerElement(arr);
    vector<int> nse = nextSmallerElement(arr);
    int n = arr.size();
    int maxArea = 0;
    for (int i = 0; i< n; i++){
        int width = (nse[i] - pse[i]) - 1;
        int height = arr[i];
        int area = width * height;
        maxArea = max(area, maxArea);
    }

    return maxArea;
}