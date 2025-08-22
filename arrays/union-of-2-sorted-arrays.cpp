#include<bits/stdc++.h>
using namespace std;

// vector <int> removeDuplicates(vector<int>& arr){
//     int i = 0;
//     for(int j=1; j< arr.size(); j++){
//         if(arr[j]!=arr[i]){
//             arr[i+1]=arr[j];
//             i++;
//         }
//     }
//     arr.resize(i+1);
//     return arr;
// }

// merge them and remove duplicate
vector<int> UnionOfTwoSortedArrays(vector<int> & v1, vector <int>& v2){
    vector <int> temp;
    size_t left = 0;
    size_t right = 0;

    while(left < v1.size() && right < v2.size()){
        if(v1[left] <= v2[right]){
            if(temp.empty() || temp.back() != v1[left]){
                temp.push_back(v1[left]);
            }
            left++;
        }
        else {
            if(temp.empty() || temp.back() != v2[right]){
                temp.push_back(v2[right]);
            }
            right++;
        }
    }
    while(left < v1.size()){
        if(temp.empty() || temp.back() != v1[left])       // avoid duplicate
            temp.push_back(v1[left]);
        left++;
    }
    while(right < v2.size()){
        if(temp.empty() || temp.back() != v2[right])      // avoid duplicate
            temp.push_back(v2[right]);
        right++;
    }

    // int i = 0;
    // for(size_t j=1; j< temp.size(); j++){
    //     if(temp[j]!=temp[i]){
    //         temp[i+1]=temp[j];
    //         i++;
    //     }
    // }
    // temp.resize(i+1);
    return temp;

}

vector <int> IntersectionOfTwoSortedArrays(vector<int> & v1, vector<int>& v2){
    size_t i = 0,j = 0;
    vector<int> result;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            i++;
        }
        else if(v1[i] > v2[j]){
            j++;
        }
        else{
            result.push_back(v1[i]);
            i++;
            j++;
        }
    }
    return result;
}

int main(){
    vector<int> v1 = {1,1,2,3,4,5};
    vector<int> v2 = {2,3,4,4,5,6,7,8,8,8 };

    vector <int> result1 = UnionOfTwoSortedArrays(v1,v2);
    vector <int> result2 = IntersectionOfTwoSortedArrays(v1,v2);
    cout << "union of 2 arrays: ";
    for(const auto it: result1){
        cout << it <<" ";
    }
    cout<<endl<<"intersection of 2 arrays:";
    for(const auto it: result1){
        cout << it <<" ";
    }

}