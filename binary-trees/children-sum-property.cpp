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


#include<bits/stdc++.h>
using namespace std;




void changeTree(TreeNode* root){
    if(!root) return ;
    int child = 0;

    if (root -> left) child += root -> left -> val;
    if (root -> right) child += root -> right -> val;

    if (child >= root -> val) root -> val = child;
    else {
        if (root -> left) root -> left -> val = root -> val;
        if (root -> right) root -> right -> val = root -> val;
    }

    changeTree(root -> left);
    changeTree(root -> right);

    // when you come back 
    int total = 0;
    if(root -> left) total += root -> left -> val;
    if(root -> right) total += root -> right -> val;


    // to ensure if it not' the leaf node?? 
    if(root -> left || root -> right) root -> val = total;


}