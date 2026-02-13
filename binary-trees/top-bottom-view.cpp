

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;

   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    // node, vertical level
    queue<pair<TreeNode* , int>> qu;

    // verrtical level : node value
    map<int, int> mpp;

    qu.push({root, 0});

    while(!qu.empty()){
        int size = qu.size();

        for(int i = 0; i< size; i++){
            auto it = qu.front();
            qu.pop();

            TreeNode* node = it.first;
            int col = it.second;

            // agar yeh colums pehli baar mila
            if(mpp.find(col) == mpp.end()) mpp[col] = node -> val;

            if(node -> left != NULL) qu.push({node -> left, col - 1});
            if(node -> right != NULL) qu.push({node -> right, col + 1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;


}


vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    // node, vertical level
    queue<pair<TreeNode* , int>> qu;

    // verrtical level : node value
    map<int, int> mpp;

    qu.push({root, 0});

    while(!qu.empty()){
        int size = qu.size();

        for(int i = 0; i< size; i++){
            auto it = qu.front();
            qu.pop();

            TreeNode* node = it.first;
            int col = it.second;

            // agar yeh colums pehli baar mila
            mpp[col] = node -> val;

            if(node -> left != NULL) qu.push({node -> left, col - 1});
            if(node -> right != NULL) qu.push({node -> right, col + 1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;


}