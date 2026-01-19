#include<bits/stdc++.h>
using namespace std;



// brute approach 
// O(N^2)
// how we approchaed,
// we are hypothetically considering another array aside it .
// for eg arr is [2,10,12,1,11] we are considering it
// [2,10,12,1,11],2,10,12,1,11

// ideally the brute appraoch is to stand at a particular element and look for the the next highest max_element
// at any particular position the next n elements is the entire circular array.

// so we do we access suppose j = 5 

// we use indx = j % n 
// 0 % 5 = 0
// 1 % 5 = 1
// 2 % 5 = 2
// 3 % 5 = 3
// 4 % 5 = 4
// 5 % 5 = 0
// 6 % 5 = 1
// 7 % 5 = 2
// 8 % 5 = 3
// 9 % 5 = 4

// TC = O(N^2)
// SC = O(N) # to give the answer



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);

        for(int i = 0 ; i < n; i++){
            for(int j = i+ 1; j < i + n; j++){
                int indx = j%n;
                if(nums[indx] > nums[i]){
                    ans[i] = nums[indx];
                    break;
                }

            }
        }
        return ans;
    }
};


// last index will be 2 * n - 1

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack <int> st;
        

        for(int i = 2*n - 1; i >= 0; i--){
            int currEle = nums[i%n];
            
            while(!st.empty() && st.top() <= currEle){
                st.pop();
            }
            if (st.empty()) ans[i%n] = -1;
            else ans[i%n] = st.top();

            st.push(currEle);
            
        }
        return ans;
    }
};




