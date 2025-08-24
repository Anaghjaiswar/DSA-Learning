#include<bits/stdc++.h>
using namespace std;

// brute force O(n^2) tc 
// int majorityElementThatAppearsMoreThanNbyTwoTimes(vector<int>& arr){
//     int n = arr.size();
//     for(int i = 0 ; i < n; i++){
//         int count = 0;
//         for(int j = 0; j < n; j++){
//             if (arr[i] == arr[j]){
//                 count++;
//             }
//         }

//         if(count > (n/2)){
//             return arr[i];
//         }
//     }
//     return -1;
// }

// better approach - hashing
// int majorityElementThatAppearsMoreThanNbyTwoTimes(vector<int>& arr){
//     unordered_map <int, int> mpp;
//     int n = arr.size();
//     for(int i =0; i < n; i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it: mpp){
//         if(it.second > (n/2)){
//             return it.first;
//         }
//     }
//     return -1;
// }


// optimal approach -- moore voting algorithm
int majorityElementThatAppearsMoreThanNbyTwoTimes(vector<int>& arr){
    int count = 0;
    int element;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(count == 0){
            element = arr[i];
            count = 1;
        }
        else if(arr[i] == element) count++;
        else count --;
    }

    // for verification to see if the majority element always exists or not 
    int count1 = 0;
    for(int i = 0; i < n; i++){
        if (arr[i] == element) count1++;
    }
    if (count1 > (n/2)) return element;

    return -1;

}



int main(){
    vector <int> v1 = {2,2,3,3,1,2,2};
    int result = majorityElementThatAppearsMoreThanNbyTwoTimes(v1);


    cout << "majority element that occured more than N/2 times:" << result; 
}