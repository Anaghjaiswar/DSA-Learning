#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int value){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == value) return i+1;
    }
    return -1;
}


int main(){
    vector<int> v1 = {2,3,4,5,6,7,8,9};
    int value = 6;

    int position = linearSearch(v1, value);
    if(position == -1) cout << "Element not found";
    else cout << "Element found at position - "<< position;

}
