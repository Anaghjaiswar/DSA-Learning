

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


int minDepth(TreeNode* root){
    if(root == NULL) return 0;

    int lh = minDepth(root -> left);
    int rh = minDepth(root -> right);

    // if left is null must go to right
    if(root -> left == NULL) return 1 + rh;
    if(root -> right == NULL) return 1 + lh;

    return 1 + min(lh,rh);
}