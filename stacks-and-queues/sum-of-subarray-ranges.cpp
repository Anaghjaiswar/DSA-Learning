#include<bits/stdc++.h>
using namespace std;


// # sum of subarray ranges 
// burte apporacj
// traverse thriught all subarrays
// keep a track on largest adn smalelst
// keep tracking their difference and add on

// TC = O(N^2) , SC = O(1)
int sumOfSubArrayMinimimBrute(vector<int> & arr){
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++){
        int largest = arr[i];
        int smallest = arr[i];
        for(int j = i + 1; j < n; j++){
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += (largest - smallest);
        }
    }
    return sum;
}


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // largest - smallest nikalna hai
        // largest == prev greatest elem and lnext greaetet elem
        // smallest == prev smallest elem and next smalles elem


        // smallest walon ka sum
        long long smallest = sumSubarrayMins(nums);
        long long largest =  sumSubarrayMax(nums);
        return largest - smallest;
    }

private:
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = previousSmallestElement(arr);
        vector<int> nse = nextSmallestElement(arr);
        int n = arr.size();

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;

            sum = (sum + arr[i] * leftCount * rightCount);
        }

        return sum;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> pge = previousGreatestElement(arr);
        vector<int> nge = nextGreatestElement(arr);
        int n = arr.size();

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - pge[i];
            long long rightCount = nge[i] - i;

            sum = (sum + arr[i] * leftCount * rightCount);
        }

        return sum;
    }

    vector<int> previousSmallestElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int currEle = arr[i];

            while (!st.empty() && arr[st.top()] >= currEle) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallestElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> previousGreatestElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int currEle = arr[i];

            while (!st.empty() && arr[st.top()] <= currEle) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreatestElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
};