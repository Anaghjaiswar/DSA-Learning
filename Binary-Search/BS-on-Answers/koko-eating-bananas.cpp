#include<bits/stdc++.h>
using namespace std;

void timecalculate(int pile, int k, int &totalTime){
    // base case
    if (pile <= 0){
        return;
    }

    totalTime += 1; // one hour spent eating k bananas

    timecalculate(pile - k, k, totalTime);
    return;
}

int minEatingBananas(vector<int>& piles, int h) {
    int p = piles.size();
    
    for (int k = 1; k <= *max_element(piles.begin(), piles.end()); k++)
    {
        int totalTime = 0;


        for (int i = 0; i < p; i++){
            timecalculate(piles[i], k, totalTime);
        }

        if (totalTime <= h) return k;
    }
    return -1;
}


int main(){
    vector<int> piles = {3,6,7,11};
    int hours = 8;
    int result = minEatingBananas(piles, hours);
    cout << result;
}