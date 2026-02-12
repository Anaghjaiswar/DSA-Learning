

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
private:
    void postorder(TreeNode* node,vector<int>& ans){
        if(node == nullptr) return ;
        postorder(node -> left,ans);
        postorder(node -> right,ans);
        ans.push_back(node -> val);
    }
};


vector<int> iterativePostOrderUsing2Stack(TreeNode* root){
    stack<TreeNode*> st1;
    stack<int> st2;
    vector<int> ans;

    if (root == NULL) return ans;
    st1.push(root);

    while(!st1.empty()){
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node -> val);
        if (node -> left != NULL) st1.push(node -> left); 
        if (node -> right != NULL) st1.push(node -> right); 
    }

    while(!st2.empty()){
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}


vector<int> iterativePostOrderUsing1Stack(TreeNode* root){
    stack<TreeNode* > st;
    vector<int> ans;

    if(root == NULL) return ans;

    TreeNode* curr = root;
    TreeNode* lastVisitedNode;

    while(curr!=NULL || !st.empty()){
        // 1. go to the extreme left & keep adding to stack
        if(curr != NULL){
            st.push(curr);
            curr = curr -> left;
        } 
        // 2. left finishes,check the right
        else{   
            // take the top's right element
            TreeNode* temp = st.top() -> right;

            // if right is already visited , tell the world
            if(temp == NULL || temp == lastVisitedNode){
                lastVisitedNode = st.top(); // but this is not lat visited this is the parent
                st.pop();
                ans.push_back(lastVisitedNode -> val);
            }
            // if right is not visited go to right
            else{
                curr = temp;
            }
        }
    }
    return ans;
}