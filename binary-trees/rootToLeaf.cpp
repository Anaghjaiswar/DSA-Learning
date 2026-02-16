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



bool isLeaf(TreeNode* root){
    return (root -> left == NULL && root -> right == NULL);
}

vector<vector<int>> RootToLeafPath(TreeNode* root){
    vector<vector<int>> ans;
    vector<int> localans;
    preorder(root, ans, localans);

    return ans;
}

void preorder(TreeNode* root, vector<vector<int>>& ans, vector<int>& localans){

    if(root == NULL) return;

    localans.push_back(root -> val);
    preorder(root -> left, ans, localans);
    if(isLeaf(root)) {
        ans.push_back(localans);
    }
    preorder(root -> right, ans, localans);

    // agar kisi node ke left aur right donojaa chuka , 
    // toh kayede se ab backtrack hi hoga , 
    // isliye backtarack karne se pehel pop kardo
    localans.pop_back();

}
