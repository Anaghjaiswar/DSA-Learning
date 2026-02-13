

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // for every node maintain a (x,y) coordiante
        queue<pair<TreeNode*, pair<int, int>>> qu;
        vector<vector<int>> ans;

        // sort by col, then auto sort by depth then sort by values
        map<int, map<int, multiset<int>>> nodes;

        if(root == NULL) return ans;
        qu.push({root, {0, 0}});

        while(!qu.empty()){
            int size = qu.size();

            for(int i = 0; i < size; i++){
                auto temp = qu.front();
                qu.pop();
                TreeNode* node = temp.first;
                int x = temp.second.first;  // Column
                int y = temp.second.second; // Row (Depth)

                nodes[x][y].insert(node->val);

                if(node -> left != NULL) qu.push({node -> left, {x - 1, y + 1}});
                if(node -> right != NULL) qu.push({node -> right, {x + 1, y + 1}});
            }
        }
    
        // for each colums
        for(auto it: nodes){ 
            vector<int> cols;
            // for each rows
            for(auto q : it.second){
                cols.insert(cols.end(), q.second.begin(), q.second.end());
            }    
            ans.push_back(cols);  

        }
        return ans;
    }
};