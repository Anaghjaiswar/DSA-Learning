

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


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);
        return ans;
    }
private:
    void inorder(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;

        inorder(node -> left,ans);
        ans.push_back(node -> val);
        inorder(node->right, ans);
    }

};


vector<int> iterativeInorderTraversal(TreeNode* node){
    // 1. maintain a stack
    stack<TreeNode* > st;
    vector<int> ans;

    // go to the extreme left possible then node then right
    while(true){
        if(node != NULL){
            st.push(node);
            node = node -> left;
        }

        // left node is null
        else{
            // if there are no eleents break
            if(st.empty()) break;

            // proces the node  and push it 
            node = st.top();
            st.pop();
            ans.push_back(node -> val);

            // now check the right
            node = node -> right;


        }
    }
    return ans;
}