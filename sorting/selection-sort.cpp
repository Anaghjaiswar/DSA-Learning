// algorithm selects minimum from array and swaps with the first 
// like array = {13,46,24,52,20,9}
// finds minimum = 9 swaps it with 13 
// takes array from 46 till last(13) finds minimum i.e. 13 and swaps it with 46
// this goes on

#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& nums){

    // takes respective array and short it on every iteration
    for(size_t i=0; i<nums.size(); i++){
        
        // assumes the first position element as mini element
        int mini = i;

        // finds the minimum index from array from the respective array
        for(size_t j = i; j <= nums.size()-1; j++){
            
            //finds minimum element
            if(nums[j] < nums[mini]) mini = j ;

        }

        // swaps the assumed minimum and actual minimum
        swap(nums[i], nums[mini]);

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

    selection_sort(v1);

    // elements in sorted order 
    cout << "Sorted order: ";
    for (const auto &it: v1){
        cout << it << " ";
    }
}
