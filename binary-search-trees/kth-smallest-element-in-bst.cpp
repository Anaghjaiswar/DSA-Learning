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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // one simple solution is inorder becuase it will be like arranging the tree in ascending order only
        int answer = -1;
        inorder(root, k, answer);
        return answer;
    }
private:    
    void inorder(TreeNode* root, int& k, int& answer){
        if (root == NULL) return;
        inorder(root -> left,k, answer);

        // optimization
        if(k == 0) return;

        k--;
        if(k == 0) {
            answer = root -> val;
            return;
        }
        inorder(root -> right, k, answer);
    }
};