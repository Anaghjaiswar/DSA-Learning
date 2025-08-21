#include <bits/stdc++.h>
using namespace std;

// without sorting
int find_second_largest_element_in_array(vector<int>& arr){
    int largest=arr[0];
    for(size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > largest){
            largest = arr[i];
        }
    }
    arr.erase(find(arr.begin(),arr.end(), largest));
    int second_largest = arr[0];
    for(size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > second_largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int second_largest(vector<int> arr){

    if (arr.size() < 2) {
        // Not enough elements
        cout << "Second largest does not exist (array too small)." << endl;
        return INT_MIN;
    }

    int largest = arr[0];
    int second_largest = INT_MIN; // or INT_MIN if negative numbers also present in array

    for(size_t i=1; i<arr.size(); i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest){
                second_largest = arr[i];
        }
    }
    if (second_largest == INT_MIN) {
        cout << "Second largest does not exist (all elements are equal)." << endl;
        return INT_MIN;
    }

    return second_largest;
}


int second_smallest(vector<int> arr){
    if (arr.size() < 2) {
        // Not enough elements
        cout << "Second smallest does not exist (array too small)." << endl;
        return INT_MAX;
    }

    int smallest = arr[0];
    int second_smallest = INT_MAX;

    for(size_t i=1; i< arr.size(); i++){
        if(arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < second_smallest){
            second_smallest = arr[i];
        }
    }

    if (second_smallest == INT_MAX) {
        cout << "Second smallest does not exist (all elements are equal)." << endl;
        return INT_MAX;
    }
    return second_smallest;
}

int main(){
    int n;
    cout << "enter array size: ";
    cin >> n;
    vector <int> v1;

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        v1.push_back(value);
    }

    int result1 = second_largest(v1);
    int result2 = second_smallest(v1);
    cout << "second largest element in array is : "<< result1;
    cout << "second smallest element in array is : "<< result2;
}