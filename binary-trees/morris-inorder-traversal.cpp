

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





vector<int> morrisInorderTraversal(TreeNode* root){
    vector<int> inorder;

    TreeNode* curr = root;

    while(curr != NULL){

        // if the current node has no left child, there is no left subtree to explore. 
        // According to Preorder rules, after visiting the root, you would immediately 
        // move to the right.
        if(curr -> left == NULL){
            inorder.push_back(curr -> val);
            curr = curr -> right;
        }
        else{
            // If there is a left child, we need to find the rightmost node in the subtree
            // This node is the last node we would visit before coming back to the current node in a standard traversal.
            TreeNode* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
            if(prev -> right == NULL){
                prev -> right = curr;
                curr = curr -> left;


            }
            // If we find the Inorder Predecessor and its right pointer is already pointing to the current node, 
            // it means we have finished traversing the entire left subtree and have returned to the root via the 
            // thread we created earlier.
            else{
                prev -> right = NULL;
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
    return inorder;

}

