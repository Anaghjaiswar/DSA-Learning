#include<bits/stdc++.h>
using namespace std;


// brute
// int totalFruits(vector<int>& fruits){
//     //your code goes here
//     int n = fruits.size();
//     int maxFruits = 0;

//     for (int start = 0; start < n; ++start) {
//         unordered_set<int> basket;
//         int count = 0;

//         for (int end = start; end < n; ++end) {
//             basket.insert(fruits[end]);

//             if (basket.size() > 2) break;

//             count++;
//         }

//         maxFruits = max(maxFruits, count);
//     }

//     return maxFruits;
// }


int totalFruits(vector<int>& fruits){

    unordered_map<int,int> basket; // storing num and freq
    int n = fruits.size();

    int left = 0;
    int right = 0;
    int maxFruits = 0;

    // tc - O(2n) 
    while(right < n){
        basket[fruits[right]]++;

        // agar kabhi basket ka size 2 se zyada hua toh 
        while(basket.size() > 2){ // this work for O(n) but overall
            // ek type of fruit ko hatana padega
            basket[fruits[left]]--;

            // agar left type ka fruit count zero ho jata hai hatao usse
            if(basket[fruits[left]] == 0){
                basket.erase(fruits[left]);
            }
            left++;

            
        }
        maxFruits = max(maxFruits, right - left + 1);
        right++;
    }
    return maxFruits;
}



int totalFruits(vector<int>& fruits){

    unordered_map<int,int> basket; // storing num and freq
    int n = fruits.size();

    int left = 0;
    int right = 0;
    int maxFruits = 0;

    // tc - O(2n) 
    while(right < n){
        basket[fruits[right]]++;

        // agar kabhi basket ka size 2 se zyada hua toh 
        if(basket.size() > 2){ // this work for O(n) but overall
            // ek type of fruit ko hatana padega
            basket[fruits[left]]--;

            // agar left type ka fruit count zero ho jata hai hatao usse
            if(basket[fruits[left]] == 0){
                basket.erase(fruits[left]);
            }
            left++;

            
        }
        if(basket.size() <=2) maxFruits = max(maxFruits, right - left + 1);
        right++;
    }
    return maxFruits;
}
    



int main(){
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    int result = totalFruits(fruits);
    cout << result;
}