#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sumOfWeights = 0;
        for(int i = 0; i < weights.size(); i++){
            sumOfWeights += weights[i];
        }
        int low = *max_element(weights.begin(), weights.end());
        int high = sumOfWeights;
        int ans;
        while(low<=high){
            int capacity = low + (high - low)/2;
            int totalDays = calculateDaysTaken(weights, capacity);
            if (totalDays <= days){
                ans = capacity;
                high = capacity - 1;
            }
            else {
                low = capacity + 1;
            }
        }
        return ans;
    }
private:
    int calculateDaysTaken(vector<int>& weights, int shipCapacity){
        int currentLoad = 0;
        int days = 1;
        for (int i = 0 ; i < weights.size(); i++){
            if((currentLoad + weights[i]) > shipCapacity){
            days++;
            currentLoad = 0;
        }
            currentLoad += weights[i];
        }
        return days;
    }
};

           