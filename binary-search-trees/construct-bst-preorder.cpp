
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack <TreeNode* > st;
        int n = preorder.size();
        if (n == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);


        for(int i = 1; i < n; i++){
            if (preorder[i] < st.top() -> val){
                TreeNode* node = new TreeNode(preorder[i]);
                st.top() -> left = node;
                st.push(node);
            }
            else {
                TreeNode* lastPoppedNode = nullptr;
                while (!st.empty() && st.top() -> val < preorder[i]){
                    lastPoppedNode  = st.top();
                    st.pop();
                }

                lastPoppedNode -> right = new TreeNode(preorder[i]);
                st.push(lastPoppedNode -> right);

            }

        } 
        st.pop();// the last node will remain so we can pop it , so net space after we get results is zero
        return root;
    }
};


