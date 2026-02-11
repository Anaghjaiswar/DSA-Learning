
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode* > qu;

        qu.push(root);

        while(!qu.empty()){
            int size = qu.size();
            vector<int> level;

            for (int i = 0; i< size; i++){
     // node ko utha lo aur pop kardo (us level me jitne bhi baithe hia)
                TreeNode* node = qu.front();
                qu.pop();

                // ab unke left aur right child process enter kardo
                if(node -> left != NULL) qu.push(node -> left);
                if(node -> right != NULL) qu.push(node -> right);

                // us level ke nodes ko list me daalo
                level.push_back(node -> val);

            }
            ans.push_back(level);
        }
        return ans;
    }

};

