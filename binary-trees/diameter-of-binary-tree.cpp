

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


int diameterOfBinaryTree(TreeNode* root){
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}

int maxDepth(TreeNode* node, int& diameter){
    if(node == NULL) return 0;

    int lh = maxDepth(node -> left, diameter);
    int rh = maxDepth(node -> right, diameter);

    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);

}