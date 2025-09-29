#include<bits/stdc++.h>
using namespace std;

// given k >= 2


bool canWePlaceCowsAtMidDistance(vector<int>& arr, int minDistance, int totalCows){
    int cowsCount = 1;
    int lastPlaced = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if((arr[i] - lastPlaced) >= minDistance){
            cowsCount++;
            lastPlaced=arr[i];

            if(cowsCount == totalCows) return true;
        }
    }
    return false;
}


int aggressiveCows(vector<int> &arr, int totalCows) {
    sort(arr.begin(), arr.end());
    int low = 1; // minimum distance could be 1, between 2 cows 
    int high = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());// maximum distance posssible between 2 cows 
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        
        if (canWePlaceCowsAtMidDistance(arr, mid, totalCows)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {4,2,1,3,6};
    int k = 2;
    int result = aggressiveCows(arr, k);
    cout << result;

}