
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor call
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> succPredBST(TreeNode *root, int key){
        TreeNode* pred = NULL; // just chota
        TreeNode* succ = NULL;  // jsut bada

        bs(root,pred,succ,key);
        int pVal = (pred != NULL) ? pred->val : -1;
        int sVal = (succ != NULL) ? succ->val : -1;

        return {pVal, sVal};

    }
private:    

    void bs(TreeNode* root, TreeNode*& pred, TreeNode*& succ, int key){

        while(root != NULL){
            if(root -> val == key){
                // iska matlab pred left me hoga aur succ right me hoga 
                // left me bhi max hoga aur max niche tak ho sakta hai toh pura left subtree dekhna padega 
                // right me bhi jsut bada matlab right subtree me minimum jsika liye pura right subtree dekhna padega 

                if(root -> left != NULL){
                    pred = root -> left;
                    while(pred -> right != NULL) pred = pred -> right;
                }

                if(root -> right != NULL){
                    succ = root -> right;
                    while(succ -> left != NULL) succ = succ -> left;
                }

                break;
            }
            else if(root -> val > key){
                // yani ki root bhi successor ho sakta hai 
                succ = root;
                // hame milega toh left em hi answer
                root = root -> left;
            }
            else{
                pred = root;
                root = root -> right;
            }

        }
    }
};