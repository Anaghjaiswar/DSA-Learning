
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor != color) {
            dfs(sr, sc, initialColor, color, image);
        }
        
        return image;
    }
private:
void dfs(int row, int col, int initialColor, int newColor, vector<vector<int>>& image) {
        int rows = image.size();
        int cols = image[0].size();

        // 1. Current pixel ka color badlo
        image[row][col] = newColor;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            // Boundary + Kya neighbor ka color purane color jaisa hai?
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                image[nRow][nCol] == initialColor) {
                dfs(nRow, nCol, initialColor, newColor, image);
            }
        }
    }
};