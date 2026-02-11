
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (root == NULL) return ans;

        // maintain a queue
        queue<TreeNode*> qu;
        qu.push(root); // push zeroth level

        while (!qu.empty()) {
            // size of the level ?
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                // node ko utha lo , process karo aur pop kardo (us level me
                // jitne bhi baithe hia)
                TreeNode* node = qu.front();
                qu.pop();

                // ab unke left aur right child process enter kardo
                if (node->left != NULL)
                    qu.push(node->left);
                if (node->right != NULL)
                    qu.push(node->right);

                if(i == size - 1) ans.push_back(node -> val);
            }

        }
        return ans;
    }
};