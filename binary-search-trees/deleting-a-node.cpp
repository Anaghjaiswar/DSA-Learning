




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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;

        // search the node first
        TreeNode* parentNode = nullptr;
        while (curr != NULL and curr->val != key) {
            parentNode = curr;

            if (curr->val > key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // handle edge cases
        if (curr == nullptr)
            return root;

        if (curr->left == nullptr || curr->right == nullptr) {

            TreeNode* child =
                (curr->left != nullptr) ? (curr->left) : (curr->right);

            if (parentNode == nullptr)
                return child;

            if (parentNode->left == curr)
                parentNode->left = child;
            else
                parentNode->right = child;

            delete curr;

            return root;
        }

        TreeNode* leftchild = curr->left;
        // find the most right most node possible

        while (leftchild -> right != NULL) leftchild = leftchild->right;
 
        leftchild->right = curr -> right;


        TreeNode* newSubTreeRoot = curr -> left;

        // if root is getting deleted means parent node not updated due to second parameter
        if (parentNode == nullptr) root = newSubTreeRoot;
        else if (parentNode -> left == curr) parentNode -> left = newSubTreeRoot;
        else parentNode -> right = newSubTreeRoot;

        delete curr;

        return root;
    }
};