#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> FourSum(vector<int>& nums, int target){
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set <int> hashset;
            for (int k = j+1; k<n; k++){
                long long Fourth = target-(nums[i] + nums[j] + nums[k]);
                
                if(hashset.find(Fourth)!= hashset.end()){
                    vector <int> temp = {nums[i], nums[j], nums[k], (int)Fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}





int main(){
    vector<int> v1 = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = FourSum(v1, target);

    for (auto it : ans)
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}