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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // first find target node
        vector<TreeNode*> pathToTargetNode;
        vector<int> ans;
        if (root == NULL) return ans;
        preorder(root, pathToTargetNode, target);
        int n = pathToTargetNode.size();

        for(int i = n-1; i>=0; i--){
            int distanceToAncestor = (n-1) - i;

            int remainingDistance = k - distanceToAncestor;

            TreeNode* blocker = (i == n-1) ? NULL : pathToTargetNode[i+1];
            findKDown(remainingDistance, pathToTargetNode[i], blocker, ans);
        }
        return ans;
        
    }

private:
    void findKDown(int k, TreeNode* node, TreeNode* blocker, vector<int>& ans){
        if (!node || k < 0 || node == blocker) return;

        if (k == 0){
            ans.push_back(node-> val);
        }

        findKDown(k-1, node -> left, blocker,ans);
        findKDown(k-1, node -> right, blocker,ans);
    }

    bool preorder(TreeNode* root, vector<TreeNode*>& path, TreeNode* target) {
        if (root == NULL) return false;

        path.push_back(root);

        if (isTargetMatched(root, target)) {
            return true; // Mil gaya Ab backtrack nahi karna
        }

        if (preorder(root->left, path, target)) {
            return true;
        }
        if (preorder(root->right, path, target)) {
            return true;
        }

        path.pop_back();
        return false; // means target not found here
    }
bool isTargetMatched(TreeNode* root, TreeNode* target){

    if(root == NULL || target == NULL) return false;
    return (root == target);
}
};

 
