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




TreeNode* searchingInBST(TreeNode* root, int target){
    while((root != NULL) && (root -> val != target)){
        root = (root -> val > target) ? (root -> left) : (root -> right);
    }
    return root;
}