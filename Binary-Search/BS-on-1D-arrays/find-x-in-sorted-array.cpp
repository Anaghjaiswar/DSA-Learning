#include <bits/stdc++.h>
using namespace std;

// recursive approach
int binarySearch(vector<int>& a, int low, int high,int target){
    if(low >= high) return -1;

    int mid = (low + high)/2;

    
    if(a[mid] == target) return mid;
    else if (a[mid] < target) {
        return binarySearch(a, mid+1, high, target);
    }
    else {
        return binarySearch(a,low,mid-1,target);
    }
}

// iterative approach
int binary_Search(vector<int> a, int low, int high, int target){
    while(low <= high){
        int mid = low + (high - low)/2;

        if(a[mid] == target) return mid;
        else if (a[mid] <= target) low = mid + 1;
        else high = mid -1;
    }
    return -1;
}


int main(){
    vector<int> v1 = {3,4,6,7,9,12,16,17};
    int target = 12;
    int n = v1.size();
    int result =  binary_Search(v1, 0, n-1, target);
    cout << result;
}