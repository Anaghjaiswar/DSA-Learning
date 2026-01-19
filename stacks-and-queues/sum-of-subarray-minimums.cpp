// Given an array of integers arr, find the sum of min(b), where b ranges 
//over every (contiguous) subarray of arr. Since the answer may be large, 
//return the answer modulo 10^9 + 7.



// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104


// brute
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = (int) (1e9 + 7);

        for (int i = 0 ; i < n; i++){
            int mini = arr[i];
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        return sum;
    }
};



class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = previousSmallerElement(arr);
        vector<int> nse = nextSmallerElement(arr);
        int mod = 1e9 + 7;
        int n = arr.size();

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;

            sum = (sum + arr[i] * leftCount * rightCount) % mod;
        }

        return (int)sum;
    }

private:
    vector<int> previousSmallerElement(vector<int>& arr) {
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

    vector<int> nextSmallerElement(vector<int>& arr) {
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
};