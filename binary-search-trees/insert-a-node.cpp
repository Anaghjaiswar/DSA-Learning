#include<bits/stdc++.h>
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



class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* justBeforeInsertNode = NULL;

        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->val < val) {
                justBeforeInsertNode = curr;
                curr = curr->right;
            } else {
                justBeforeInsertNode = curr;
                curr = curr->left;
            }
        }
        if (justBeforeInsertNode == NULL) {
            TreeNode* root = new TreeNode(val);
            return root;
        }
        if (justBeforeInsertNode->val < val) {
            justBeforeInsertNode->right = new TreeNode(val);
        } else {
            justBeforeInsertNode->left = new TreeNode(val);
        }

        return root;
    }
};