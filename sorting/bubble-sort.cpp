#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& nums){
    for(int j = nums.size()-1; j >= 1; j--){

        bool didSwap = false;


        for (int i = 0; i < j ; i++){
            if (nums[i] > nums[i+1]) {
                swap(nums[i],nums[i+1]);
                didSwap = true;
            }
        }

        if(!didSwap) break;
    }
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

    bubble_sort(v1);

    cout << "Elements in sorted order: ";
    for (const auto &it : v1){
        cout << it << " ";
    }
}