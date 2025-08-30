#include <bits/stdc++.h>
using namespace std;

// brute force
int lengthOfLongestConsecutiveSequence(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;

    sort(nums.begin(), nums.end()); // O(n log n)
    int maxCount = 1;

    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates

        int count = 1;
        int nextValue = nums[i] + 1;

        for(int j = i+1; j < n; j++){
            if(nums[j] == nextValue){
                count++;
                nextValue++;
            }
            else if(nums[j] > nextValue) break; // stop early
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i< n; i++){
        st.insert(nums[i]);
    }

    for(auto it: st){

        // “Is the current element it the start of a consecutive sequence?”
        // What it means:
        // it is the current element from the unordered set.
        // it-1 means the previous integer just before it.
        // st.find(it-1) checks if (it-1) exists in the set.
        // If it does not exist, then st.find(it-1) will return st.end().
        
        if(st.find(it-1) == st.end())
        {
            int cnt = 1;
            int x = it;

            while (st.find(x+1) != st.end()){
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


int main(){
    vector<int> v1 = {102,4,100,1,101,3,2,1,1};
    int result = longestConsecutive(v1);
    cout << result;
}