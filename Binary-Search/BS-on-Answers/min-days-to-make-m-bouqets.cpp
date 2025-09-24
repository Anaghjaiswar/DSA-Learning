#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        // if required flowers are less than the total flowers. 
        if (m > bloomDay.size() / k) return -1;


        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;
        
        while(low <= high){
            int mid = low + (high - low ) / 2;

            bool isPossible = is_mid_the_day(bloomDay, k, m, mid);
            if (isPossible){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

private:
    bool is_mid_the_day(vector<int>& bloomDay, int k , int m, int day){
        int bouqets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= day){
                flowers++;
                if(flowers == k){
                    bouqets++;
                    flowers = 0; // resetted for next bouqet
                }
            }
            else flowers = 0; // reset if flower not bloomed
        }
        return (bouqets >= m);
    }
};