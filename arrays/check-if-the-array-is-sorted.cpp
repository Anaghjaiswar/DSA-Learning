#include <bits/stdc++.h>
using namespace std;

bool isArraySortedInAscending(vector<int> &a, int n){
    for (int i = 1; i < n; i++){
        if(a[i-1] <= a[i]){}
        else return false;
    }
    return true;
}

bool isArraySortedInDescending(vector<int> &a, int n){
    for (int i = 1; i < n; i++){
        if(a[i-1] >= a[i]){
        }
        else return false;
    }
    return true;
}

bool isArraySorted(vector<int> v1){
    int n = v1.size();
    if (isArraySortedInAscending(v1,n) || isArraySortedInDescending(v1,n)){
        return true;
    }
    return false;
}

int main() {
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> a2 = {5, 4, 3, 2, 1};
    vector<int> a3 = {1, 3, 2, 5};

    cout << isArraySorted(a1) << "\n"; // 1 (true)
    cout << isArraySorted(a2) << "\n"; // 1 (true)
    cout << isArraySorted(a3) << "\n"; // 0 (false)
}
