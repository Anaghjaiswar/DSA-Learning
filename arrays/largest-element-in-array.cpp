#include <bits/stdc++.h>
using namespace std;


int find_largest_element_in_array(vector<int>& arr){
    int largest = arr[0];

    for(size_t i=0;i<arr.size();i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
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

    int largest_number = find_largest_element_in_array(v1);
    cout << "largest element in array is : "<< largest_number;
}