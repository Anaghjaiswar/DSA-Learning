#include<bits/stdc++.h>
using namespace std;

// brute - O(nlogn) + o(2n)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    

    for(int i = 0; i < n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        // !ans.empty()
        // Check karta hai ki ans vector khali na ho. Agar pehle se koi interval store hai tabhi compare karenge.

        // end <= ans.back()[1]
        // ans.back() ka matlab hai last interval jo abhi tak answer me dala hai.
        // [1] ka matlab us interval ka end value.

        // Agar current interval ka end ≤ last interval ke end hai → matlab current interval poora already covered hai. 
        if (!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for (int j = i + 1; j < n; j++){
            if (intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
            } else break;
        }
        ans.push_back({start,end});
    }
    return ans;

}



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            if (ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);

            }
            else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }        
        }
        return ans;

    }
}; 




int main(){ 
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(intervals);

    for (auto it : ans)
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
