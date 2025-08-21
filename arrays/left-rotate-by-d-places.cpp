#include<bits/stdc++.h>
using namespace std;

// brute-force approach
void leftRotateByDPlace(vector<int>& arr, int d){
    if (arr.empty()) return;
    if (d == 0) return;


    vector<int> temp(d);
    
    for(int i=0; i<d; i++){
        temp[i]=arr[i];
    }

    for(size_t i=d; i < arr.size(); i++){
        arr[i-d]=arr[i];
    }


    // put back temp
    int j = 0;
    for(size_t i = arr.size()-d; i < arr.size(); i++){
        arr[i] = temp[j];
        j++;
    }
    return;

}


// optimal approach with in-place rotation
void leftRotate(vector<int>& arr, int d){
    int n = arr.size();
    if (n == 0) return;
    if (d == 0) return;

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.begin() + n);
    reverse(arr.begin(), arr.end());

}

void rightRotate(vector<int>& arr, int d){
    int n = arr.size();
    if (n == 0) return;
    if (d == 0) return;

    reverse(arr.end()-d, arr.end());
    reverse(arr.begin(), arr.end()-d);
    reverse(arr.begin(), arr.end());
    
}

int main(){
    vector <int> v1 = {1,3,4,5,6,8};
    int d;
    cout<< "Enter no. of times to be rotated: ";
    cin >> d;

    d = d%v1.size();
    
    // leftRotate(v1, d);
    rightRotate(v1,d);
    for(const auto it: v1){
        cout << it<< " ";
    }
    
}