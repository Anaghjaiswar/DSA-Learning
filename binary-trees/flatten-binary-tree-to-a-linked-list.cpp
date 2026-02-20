

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




// brute approach users O(N) space complexity
void flattenTree(TreeNode* root){
    vector<TreeNode*> ans;
    if(!root) return;
    preorderTraversal(root, ans);

    for(int i = 0; i < ans.size() -1; i++){
        ans[i] -> left = NULL;
        ans[i] -> right = ans[i+1];
    }

    // for the last node 
    ans.back()->left = nullptr;
    ans.back()->right = nullptr;
}

void preorderTraversal(TreeNode* root, vector<TreeNode* >& ans){
    if(root == NULL) return;
    ans.push_back(root);
    preorderTraversal(root -> left, ans);
    preorderTraversal(root -> right, ans);
}



class Solution {
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        flatten(root -> right);
        flatten(root -> left);

        root -> right = prev;
        root -> left = nullptr;

        prev = root;

    }
};

// badiya question