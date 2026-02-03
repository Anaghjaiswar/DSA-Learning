#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // approach
        // we need to a make a prefx sum matrix of this matrix
        // after that we pass rows of that matrix to largest rect in histogram
        // function return the maxM across the returning avleus of all thr rows
        // from that fucntions
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> preSumMatrix(rows, vector<int>(cols, 0));

        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == '1')
                    sum += 1;
                else
                    sum = 0;

                preSumMatrix[i][j] = sum;
            }
        }

        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            maxArea =
                max(maxArea, largestRectangleArea(preSumMatrix[i]));
        }
        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previousSmallerElement(heights);
        vector<int> nse = nextSmallerElement(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int area = (nse[i] - pse[i] - 1) * heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); // pushing index values
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top(); 
            st.push(i);         
        }
        return ans;
    }
};


// using 1-d heights array

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;

            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previousSmallerElement(heights);
        vector<int> nse = nextSmallerElement(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int area = (nse[i] - pse[i] - 1) * heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); // pushing index values
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top(); 
            st.push(i);         
        }
        return ans;
    }
};