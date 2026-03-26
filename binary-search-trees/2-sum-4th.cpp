
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



// // brute
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         // make the tree in inorder , as it would we already sorted in ascending order
//         vector<int> path;
//         inorder(root,path);

//         // now perform standard 2 sum
//         int left = 0;
//         int right = path.size() - 1;
//         while(left < right){
//             int sum = path[left] + path[right];
//             if (sum == k) return true;
//             else if(sum < k) left++;
//             else right--;


//         }
//         return false;

//     }
// private:
//     void inorder(TreeNode* root, vector<int>& path){
//         if(root == nullptr) return;
//         inorder(root -> left,path);
//         path.push_back(root -> val);
//         inorder(root -> right, path);
//     }
// };


bool findTarget(TreeNode* root , int k){
    unordered_map <int, TreeNode*> mpp;
    bool ans = false;
    inorder(root, mpp, k, ans);
    return ans;

}

void inorder(TreeNode* root, unordered_map<int, TreeNode*>& mpp, int target, bool& answer){
    if (root == NULL) return;

    inorder(root -> left, mpp, target, answer);

    // optimization
    if(answer) return;

    if(mpp.find(root -> val) != mpp.end()){
        answer = true;
    }
    mpp[target - (root -> val)] = root;
    inorder(root -> right, mpp, target, answer);

}