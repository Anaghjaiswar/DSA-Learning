

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

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        if (n == 0)
            return nullptr;

        // we will hash the values of the hashmap of inorrder
        // number, index
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[inorder[i]] = i;
        }

        return solve(preorder, 0, n - 1, inorder, 0, n - 1, mpp);
    }

private:
    TreeNode *solve(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd,
                    unordered_map<int, int> &mpp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRootIndex = mpp[root->val];
        int numsLeft = inRootIndex - inStart;

        root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder,
                           inStart, inRootIndex - 1, mpp);
        root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder,
                            inRootIndex + 1, inEnd, mpp);

        return root;
    }
};