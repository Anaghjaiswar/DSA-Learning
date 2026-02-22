
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



// brute
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // make the tree in inorder , as it would we already sorted in ascending order
        vector<int> path;
        inorder(root,path);

        // now perform standard 2 sum
        int left = 0;
        int right = path.size() - 1;
        while(left < right){
            int sum = path[left] + path[right];
            if (sum == k) return true;
            else if(sum < k) left++;
            else right--;


        }
        return false;

    }
private:
    void inorder(TreeNode* root, vector<int>& path){
        if(root == nullptr) return;
        inorder(root -> left,path);
        path.push_back(root -> val);
        inorder(root -> right, path);
    }
};



void inorder1(TreeNode* root, stack<int>& st1){
    if(root == NULL) return;
    inorder1(root -> left, st1);
    st1.push(root -> val);
    inorder1(root -> right, st1);
}

void inorder2(TreeNode* root, stack<int>& st2){
    if(root == NULL) return;
    inorder1(root -> right, st2);
    st2.push(root -> val);
    inorder1(root -> left, st2);
}


// better
bool findTarget(TreeNode* root, int k){
    stack<int> st1;   // standard inorder
    stack<int> st2;   // reverse inorder

    inorder1(root, st1);
    inorder2(root, st2);

    while(!st1.empty()){
        if (st1.top() + st2.top() == k) return true;
        st1.pop();
        st2.pop();
    }
    return false;

}
