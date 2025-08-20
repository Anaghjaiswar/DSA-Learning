#include <bits/stdc++.h>
using namespace std;

// vector<int> Quick_Sort(vector<int>& arr, int p){ // p will be passed as zero

//     // base case
//     if (arr.size() == 1 || arr.size() == 0) return arr;

//     int pivot = arr[p];
//     vector<int> small_arr;
//     vector<int> big_arr;
//     vector<int> equal_arr;


//     for(int i = 0; i < arr.size(); i++){
//         if (arr[i] < arr[p]){
//             small_arr.push_back(arr[i]);
//         }
//         else if(arr[i] > arr[p]) {
//             big_arr.push_back(arr[i]);
//         }
//         else equal_arr.push_back(arr[i]);
//     }

//     vector<int> sorted_small = Quick_Sort(small_arr, 0);
//     vector<int> sorted_big = Quick_Sort(big_arr, 0);


//     sorted_small.insert(sorted_small.end(), equal_arr.begin(), equal_arr.end());
//     sorted_small.insert(sorted_small.end(), sorted_big.begin(), sorted_big.end());

//     return sorted_small;


// }
int f(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j){

        // places i to the index which is greater than the pivot 
        while (arr[i] <= pivot && i <= high-1){
            i++;
        }
        // places j to the index which is smaller than the pivot 
        while(arr[j] > pivot && j >= low+1){
            j--;
        }

        // now swap them
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void QuickSort(vector<int>& a, int low, int high){
    if(low < high){
        int partition_index = f(a,low, high);
        QuickSort(a, low, partition_index-1);
        QuickSort(a, partition_index+1, high);


    }
}
