

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


// brute


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left && right) return root; 
        
        // matlab left se na p mila na q toh saari umeed right side se hai 
        if (left == NULL) return right;
        //otehrwise return right
        return left;
    }
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){

            if (root -> val > p -> val && root -> val > q -> val){
                root = root -> left;
            }

            else if (root -> val < p-> val && root -> val < q -> val) root = root -> right;

            else return root;
        }
        return nullptr;
    }
};