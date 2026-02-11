

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preorder(root,ans);

        return ans;

    }
private:
    void preorder(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;
        ans.push_back(node->val);

        preorder(node->left, ans);
        preorder(node->right, ans);
    }
};


vector<int> iterativePreorderTraversal(TreeNode* root){

    vector<int> ans;
    if (root == NULL) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        // extract the node
        TreeNode* node = st.top();
        st.pop();

        // process the node , we first process right then left bcz of stask LIFO approch it will correctly iterate
        ans.push_back(node -> val);
        if(node -> right != NULL) st.push(node -> right);
        if(node -> left != NULL) st.push(node -> left);
    }
    return ans;

}