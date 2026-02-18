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

 


// another approach -- tree graph approach 
// construct parent pointers

vector<int> allNodeAtaDistanceK(TreeNode* root, TreeNode* target, int k){
    vector<int> ans;
    if(!root) return ans;
    

    // MARK PARENTS-------------------------------------------------------------------------------------
    unordered_map<TreeNode*, TreeNode*> parent_track;
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty()){
        int size = qu.size();
        for(int i = 0;i< size; i++){
            TreeNode* temp = qu.front();
            qu.pop();

            if(temp -> left){
                qu.push(temp -> left);
                parent_track[temp-> left] = temp;
            }

            if(temp -> right){
                qu.push(temp-> right);
                parent_track[temp->right] = temp;
            }
        }
    }
    // # ========================================================================================
    unordered_map<TreeNode* , bool> visited;

    // since our previous queue is empty now we can reuse it again
    

    // we need to go radially upwards and downwards from the target node
    qu.push(target);
    visited[target] = true;

    int curr_level = 0; // when this is k we will just print all the elements in the queue

    while(!qu.empty()){
        int size = qu.size();

        if(curr_level == k) break;

        for(int i = 0 ; i< size; i++){
            TreeNode* temp = qu.front();
            qu.pop();

            if(temp -> left && !visited[temp-> left]){
                qu.push(temp-> left);
                visited[temp -> left] = true;
            }
            if(temp -> right && !visited[temp-> right]){
                qu.push(temp-> right);
                visited[temp -> right] = true;
            }

            if (parent_track[temp] && !visited[parent_track[temp]]){
                qu.push(parent_track[temp]);
                visited[parent_track[temp]] = true;
            }
            
        }
        curr_level++;
    }

    while(!qu.empty()){
        ans.push_back(qu.front()-> val);

        qu.pop();

    }
    return ans;

}