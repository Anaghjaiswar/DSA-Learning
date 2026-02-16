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


bool isTargetMatched(TreeNode* root, TreeNode* target){

    if(root == NULL || target == NULL) return false;
    return (root == target);
}

vector<TreeNode* > RootToTragetPath(TreeNode* root, TreeNode* target){
    vector<TreeNode* > ans;
    if(root == NULL) return ans;
    preorder(root, ans, target);
    return ans;
}


bool preorder(TreeNode* root, vector<TreeNode* >& path, TreeNode* target){

    if(root == NULL) return false;

    path.push_back(root);

    if(isTargetMatched(root, target)) {
        return true; // Mil gaya! Ab backtrack nahi karna
    }

    if (preorder(root -> left, path, target)){
        return true;
    }
    if(preorder(root -> right, path, target)){
        return true;
    }

    path.pop_back();

    return false; // means target not found here 
}

