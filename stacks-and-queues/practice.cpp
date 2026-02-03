#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        int currEle = nums[i];

        while(!st.empty() && nums[st.top()] <= currEle){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : nums[st.top()];
        st.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        int currEle = nums[i];

        while(!st.empty() && nums[st.top()] >= currEle){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : nums[st.top()];
        st.push(i);
    }
    return ans;
}


vector<int> prevGreaterElement(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
        int currEle = nums[i];

        while(!st.empty() && nums[st.top()] <= currEle){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : nums[st.top()];
        st.push(i);
    }
    return ans;
}



vector<int> prevSmallerElement(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
        int currEle = nums[i];

        while(!st.empty() && nums[st.top()] >= currEle){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : nums[st.top()];
        st.push(i);
    }
    return ans;
}



vector<int> nextGreatestEle(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    int max_so_far = INT_MIN;
    
    for(int i = n - 1; i >= 0; i--){
        ans[i] = max_so_far;
        max_so_far = max(max_so_far, nums[i]);
    }
    return ans;
}

vector<int> nextSmallestEle(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    int min_so_far = INT_MAX;

    for(int i = n - 1; i >= 0; i--){
        ans[i] = min_so_far;
        min_so_far = min(min_so_far, nums[i]);
    }
    return ans;
}

vector<int> prevGreatestEle(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    int max_so_far = INT_MIN;

    for(int i = 0; i < n; i++){
        ans[i] = max_so_far;
        max_so_far = max(max_so_far, nums[i]);
    }
    return ans;
}
vector<int> prevSmallestEle(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);
    int min_so_far = INT_MAX;

    for(int i = 0; i < n; i++){
        ans[i] = min_so_far;
        min_so_far = min(min_so_far, nums[i]);
    }
    return ans;
}