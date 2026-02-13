

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;

    //constructor call
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool isLeafNode(TreeNode* root){
    return (root -> left == NULL  && root -> right == NULL);
}

void addLeftBoundary(TreeNode* root, vector<int>& ans){
    TreeNode* curr = root -> left;

    while(curr){
        if (!isLeafNode(curr)) ans.push_back(curr -> val);
        if (curr -> left) curr = curr -> left;
        else curr = curr -> right;
    }
}

void addLeaves(TreeNode* root, vector<int>& ans){
    if(isLeafNode(root)) {
        ans.push_back(root -> val);
        return;
    }

    if (root-> left) addLeaves(root -> left, ans);
    if (root-> right) addLeaves(root -> right, ans);
}

void addRightBoundary(TreeNode* root, vector<int>& ans){
    TreeNode* curr = root -> right;

    stack<int> st; // to get ACW direction

    while(curr){
        if(!isLeafNode(curr)) st.push(curr-> val);
        if(curr-> right) curr = curr -> right;
        else curr = curr -> left;
    }   

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}


vector<int> boundaryTraversal(TreeNode* root){
    vector<int> ans;

    if(root == NULL) return ans;

    if(!isLeafNode(root)) ans.push_back(root -> val);
    addLeftBoundary(root, ans);
    addLeaves(root,ans);
    addRightBoundary(root, ans);
    return ans;
}