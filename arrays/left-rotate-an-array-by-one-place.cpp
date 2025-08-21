#include<bits/stdc++.h>
using namespace std;

void leftRotateByOnePlace(vector<int>& arr){
    if(arr.size()<2){
        return;
    }

    int temp = arr[0];

    for(size_t i = 1; i < arr.size(); i++){
        arr[i-1]=arr[i];
    }

    arr[arr.size()-1]=temp;
}
int main(){
    vector <int> v1 = {1,3,4,5,6,8};
    leftRotateByOnePlace(v1);
    for(const auto it: v1){
        cout << it<< " ";
    }
}