

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



int maxDepth(TreeNode* root) {
        int maxDepth = 0;
    if(root == NULL) return maxDepth;
    queue<TreeNode* > qu;
    qu.push(root);
    while(!qu.empty()){
        int size = qu.size();
        maxDepth++; // new level is starting
        for(int i = 0; i < size; i++){
            TreeNode* node = qu.front();
            qu.pop();
            if (node->left != NULL) qu.push(node->left);
            if (node->right != NULL) qu.push(node->right);
        }
    }
    return maxDepth;
}


int maxDepth(TreeNode* root){
    if(root == NULL) return 0;

    int lh = maxDepth(root -> left);
    int rh = maxDepth(root -> right);

    return 1 + max(lh,rh);
}