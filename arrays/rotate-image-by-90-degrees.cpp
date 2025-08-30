#include<bits/stdc++.h>
using namespace std;


// brute force
// void rotateMatrixBy90Degrees(vector<vector<int>> &mat, int n) {
//     vector<vector<int>> tempMatrix(n, vector<int>(n));

//     for(int i = n-1; i >= 0; i--){
//         for(int j = 0; j < n; j++){

//             tempMatrix[j][n-i-1] = mat[i][j];

//         }
//     }


//     // copy back to original matrix
//     // mat = tempMatrix; or you can write 
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             mat[i][j] = tempMatrix[i][j];
//         }
//         cout << "\n";
//     }


// }


void rotateMatrixBy90Degrees(vector<vector<int>> &mat, int n) {
    // vector<vector<int>> tempMatrix(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

           swap(mat[i][j], mat[j][i]);

        }
    }

    for(int i = 0 ; i< n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }


}


int main() {
    int n = 4;
    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = (rand() % 20) + 1; // 1 se 20 tak
        }
    }

    // print karna hai
    cout << "original matrix" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    rotateMatrixBy90Degrees(matrix, n);
    cout << "after rotating by 90 degrees: "<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}