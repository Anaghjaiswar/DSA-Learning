#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int size, int value){
    for(int i = 0 ; i < size; i++){
        if(arr[i] == value)
            return i+1; 
    }
    return -1;
}

int binarysearch(int arr[], int low, int high, int value){
    if (low > high) {
        return -1;
    }
    int mid = (low + high)/2;

    if (arr[mid] == value){
        return mid + 1;
    }

    if (value > arr[mid]){
        return binarysearch(arr, mid+1, high, value);
    }
    else {
        return binarysearch(arr, low, mid-1, value);
    }
}

int main(){
    int n;
    cout << "enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "enter elements: ";
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int value;
    cout << "Enter value to be searched: ";
    cin >> value;

    // Linear Search
    int position = linearSearch(arr.data(), n, value);
    if (position < 0) cout << "element not found\n";
    else cout << "element - " << value << " found at position - " << position << "\n";

    // Binary Search (after sorting)
    sort(arr.begin(), arr.end());
    position = binarysearch(arr.data(), 0, n-1, value);
    if (position < 0) cout << "element not found (binary search)\n";
    else cout << "element - " << value << " found at position - " << position << " (binary search)\n";
    return 0;
}