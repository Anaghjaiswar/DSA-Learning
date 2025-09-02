#include <bits/stdc++.h>
using namespace std;

// optimal approach
void printRowElements(int row){
    int ans = 1;
    cout << ans << " ";
    for(int col = 1; col < row; col++){
        ans = (ans * (row - col))/col;
        cout << ans << " ";
    }
}


int main(){
    int row;
    cout << "Enter row: ";
    cin >> row;
    printRowElements(row);

}