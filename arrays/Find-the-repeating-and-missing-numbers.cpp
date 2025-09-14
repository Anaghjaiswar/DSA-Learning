// Problem Statement: You are given a read-only array of N integers 
// with values also in the range [1, N] both inclusive. Each integer 
// appears exactly once except A which appears twice and B which is missing. 
// The task is to find the repeating and missing numbers A and B where A 
// repeats twice and B is missing.



#include<bits/stdc++.h>
using namespace std;

vector<int> findRepeatingAndMissingNumber(vector<int> nums){
    int n = nums.size();
    vector<int> temp;
    vector<int> hash(n+1, 0);

    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }

    int repeating = -1, missing = -1;
    for(size_t i = 1; i < hash.size(); i++){
        cout << hash[i] << " "; 
        if (hash[i] == 0){
            
        }
        if (hash[i] == 2){
            int missing = i;
        }
    }
    temp.push_back(repeating);

    return temp;


}



int main(){
    vector<int> v1 = {3,1,2,5,3};
    vector<int> result = findRepeatingAndMissingNumber(v1);
    cout << result[0] << " " << result[1];
}