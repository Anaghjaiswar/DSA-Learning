
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


TreeNode* ceilingInBST(TreeNode* root, int key){
    TreeNode* ceil = nullptr;

    while(root != NULL){
        if(root -> val == key) return root;

        if(root -> val > key){
            ceil = root;
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return ceil;

}



TreeNode* floorInBST(TreeNode* root, int key){
    TreeNode* floor = nullptr;

    while(root != NULL){
        if(root -> val == key) return root;

        if(root -> val < key){
            floor = root;
            root = root -> right;
        }
        else{
            root = root -> left;
        }
    }
    return floor;

}



// To find Ceiling (>= key): When you find a value greater than the key, save it and go left (try to get smaller).

// To find Floor (<= key): When you find a value smaller than the key, save it and go right (try to get larger).

void printTree(TreeNode* root){

    if(root == nullptr) return;
    cout << root -> val;

    printTree(root->left);
    printTree(root->right);
}


vector<int> floorCeilOfBST(TreeNode* root,int key){
    int ceil = -1;
    int floor = -1;
    vector<int> ans;

    printTree(root);
    
    while (root != NULL){
        if(root -> val == key) {
            // this is the floor this is the ceil
            ans.push_back(root -> val);
            ans.push_back(root -> val);
            return ans;
        }
        if(root -> val > key){
            ceil = root -> val;
            root = root -> left;
        }
        else{
            floor = root -> val;
            root = root -> right;
        }
    }

    ans.push_back(floor);
    ans.push_back(ceil);

    return ans;

}


int main(){
    TreeNode* root = new TreeNode(8);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(12);
    root -> left -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(6);

    root -> right -> left = new TreeNode(10);
    root -> right -> right = new TreeNode(14);
    int key = 11;
    vector<int> answer = floorCeilOfBST(root, key);
    for(int i: answer){
        cout << i << " ";
    }
    return 0;
}