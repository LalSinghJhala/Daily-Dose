#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* node, int val) {
        if(!node) return 0;

        val = (2* val) + (1 * node->val);

        if(node->left == NULL && node->right == NULL ) {
            return val;
        }

        return solve(node->left, val) + solve(node->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
       return solve(root, 0);
    }
};









/*
     METHOD - 1;

      void dfs(TreeNode* node, string path, vector<string>& paths) {
        if(!node) {
            return;
        }
        path.push_back('0' + node->val);
        if(node->left == NULL && node->right == NULL) {
            paths.push_back(path);
            return;
        }
        dfs(node->left, path, paths);
        dfs(node->right, path, paths);
    }



class Solution {
public:
   

    int sumRootToLeaf(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        int total = 0;
        for(string path : paths) {
            total += stoi(path, nullptr, 2);
        }
        return total;
    }
};


*/

