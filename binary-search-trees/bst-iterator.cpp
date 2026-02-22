
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
class BSTIterator {
    stack<TreeNode* >st;
public:
    BSTIterator(TreeNode* root) {
        while(root != NULL){
            st.push(root);
            root = root -> left;
        }
    }
    
    int next() {

        TreeNode* top = st.top();
        int ans = top -> val;
        st.pop();
        if(top -> right != NULL){
            top = top -> right;
            while(top != NULL){
                st.push(top);
                top = top -> left;
            }

        }
        
        return ans;

    }
    
    bool hasNext() {    
        if(st.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */