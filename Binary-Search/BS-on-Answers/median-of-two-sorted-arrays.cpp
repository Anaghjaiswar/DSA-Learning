#include<bits/stdc++.h>
using namespace std;


vector<int> merge_sort(vector<int>& nums1, vector<int>& nums2){
    int left = 0;
    int right = 0;
    int n = nums1.size();
    int m = nums2.size();
    vector<int> temp;
    while ((left < n) && (right < m)){
        if (nums1[left] < nums2[right]){
            temp.push_back(nums1[left]);
            left++;
        }
        else {
            temp.push_back(nums2[right]);
            right++;
        }
    }
    while (left < n) temp.push_back(nums1[left++]);
    while (right < m) temp.push_back(nums2[right++]);
    return temp;
}

    
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double median;
    vector <int>merged_array = merge_sort(nums1, nums2);
    int n = merged_array.size();

    if (n % 2 == 1) median = merged_array[n/2];
    else {
        median = (merged_array[(n/2) - 1] + merged_array[n/2])/2.0;
    }
    return median;

}

int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result;
}