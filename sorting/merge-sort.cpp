#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& arr, int low, int mid, int high){
    vector <int> temp;

    // taking two pointers
    int left = low;
    int right = mid+1;

    // picking smallest from both arrays and adding it to temp array after that increasing pointers in respective arrays
    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // for leftover elements in any array if one is completed
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // copying the temp array to main array
    for (int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}



void merge_sort(vector<int>& arr, int low, int high){
    // base case
    if(low >= high) return;

    int mid = (low + high)/2;

    // sort 1st half
    merge_sort(arr, low, mid);

    // sort 2nd half
    merge_sort(arr, mid+1, high);

    // merge both sorted arrays
    merge(arr, low, mid, high);

}

int main(){
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    vector <int> v1;
    cout << "Enter elements: ";
    for(int i= 0; i < n ; i++) {
        int value;
        cin >> value;
        v1.push_back(value);
    }

    merge_sort(v1, 0, n-1);
    
     // elements in sorted order 
    cout << "Sorted order: ";
    for (const auto &it: v1){
        cout << it << " ";
    }


}