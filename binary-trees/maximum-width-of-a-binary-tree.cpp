
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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;    
                // node, index
        queue<pair<TreeNode* , int>> qu;
        if(root == nullptr) return ans;

        qu.push({root, 0});

        while(!qu.empty()){
            int size = qu.size();

            long long level_min_index = qu.front().second;
            long long first, last;

            for(int i = 0; i < size; i++){
                TreeNode* temp_node = qu.front().first;
                long long index = (qu.front().second - level_min_index);

                qu.pop();

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (temp_node -> left) qu.push({temp_node -> left, 2*index + 1});
                if (temp_node -> right) qu.push({temp_node -> right, 2*index + 2});
                
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};