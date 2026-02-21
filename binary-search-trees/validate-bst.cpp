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
    bool isValidBST(TreeNode* root) {
        // inorder nikaalte jaayo aur saaath me comaprison karte jaayo baat khatam kahi pe bhi break ho toh return false kardo 
        // tree ka inorder traversl ascedning hota hai 
        
        bool ans = true;
        TreeNode* prevNode = nullptr;
        inorder(root, ans, prevNode);
        return ans;
    }
private:
    void inorder(TreeNode* root, bool& ans, TreeNode*& prevNode){
        if(root == NULL) return;

        inorder(root -> left, ans, prevNode);

        // optimization
        if (ans == false) return;

        if(prevNode != NULL && root -> val <= prevNode -> val){
            ans = false;
        }

        prevNode = root;
        

        inorder(root -> right, ans, prevNode);

    }
};