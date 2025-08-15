#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &nums){

    for (size_t i = 1; i < nums.size(); i++){

        for (int j = i; j > 0; j--){

            if (nums[j - 1] > nums[j]){
                
                swap(nums[j - 1], nums[j]);  // swaps

            } else {
                break; // already in order, no need to check further
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    vector<int> v1;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v1.push_back(value);
    }

    insertion_sort(v1);

    // elements in sorted order
    cout << "Sorted order: ";
    for (const auto &it : v1)
    {
        cout << it << " ";
    }
}
