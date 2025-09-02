// pascal triangle
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1

#include<bits/stdc++.h>
using namespace std;

// given the row and colums , find the exact number at that place


// brute force appraoch -- tc -- O(n-r) + O(r) + O(n)
// here we will calculate properly (R-1) C (C-1) using natural method 


// tc - O(r)
int findTheElement(int row, int col){
    int result = 1;
    for (int i = 0; i < col; i++){
        result = (result * (row - i))/(i+1);
    }
    return result;
}


int main(){
    int row, col;
    cout << "enter row no: ";
    cin >> row;
    cout << "enter column no: ";
    cin >> col;

    int result = findTheElement(row-1,col-1);
    cout << "result is :" << result;
}