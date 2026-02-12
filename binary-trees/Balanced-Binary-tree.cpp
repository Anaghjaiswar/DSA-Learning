

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


bool isBalanced(TreeNode* root){
    return maxDepth(root) != -1;
}

int maxDepth(TreeNode* node){
    if(node == NULL) return 0;

    int lh = maxDepth(node -> left);
    if(lh == -1) return -1;

    int rh = maxDepth(node -> right);
    if(rh == -1) return -1;

    if (abs(lh-rh) > 1) return -1;

    return 1 + max(lh, rh);
}