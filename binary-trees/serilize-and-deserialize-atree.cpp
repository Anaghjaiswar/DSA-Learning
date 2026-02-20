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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        queue<TreeNode*> qu;

        string ans = "";
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = qu.front();
                qu.pop();

                if (curr == nullptr)
                    ans.append("null, ");
                else {

                    ans.append(to_string(curr->val) + ",");
                    qu.push(curr->left);

                    qu.push(curr->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        vector<string> nodes = splitString(data);
        if (nodes.empty() || nodes[0] == "null")
            return nullptr;

        int n = nodes.size();

        if (nodes[0] == "null")
            return nullptr;

        // push the root node to tree first
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> qu;
        qu.push(root);

        int currIndex = 1;

        while (!qu.empty() && currIndex < nodes.size()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = qu.front();
                qu.pop();

                if (nodes[currIndex] != "null") {
                    curr->left = new TreeNode(stoi(nodes[currIndex]));
                    qu.push(curr->left);
                }

                currIndex++;

                if (currIndex < nodes.size() && nodes[currIndex] != "null") {
                    curr->right = new TreeNode(stoi(nodes[currIndex]));
                    qu.push(curr->right);
                }
                currIndex++;
            }
        }
        return root;
    }

    vector<string> splitString(string data) {
        vector<string> nodes;
        string temp = "";
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                if (!temp.empty()) {
                    nodes.push_back(temp);
                    temp = "";
                }
            } else if (data[i] != ' ') {
                temp += data[i];
            }
        }
        return nodes;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));