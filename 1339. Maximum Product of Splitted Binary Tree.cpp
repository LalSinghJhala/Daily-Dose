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
    long long totalSum = 0;
    long long maxiProduct = 0;
    const int modulo = 1e9 + 7;
public:

    long long  getTotalSum(TreeNode* root) {
        if(root == NULL) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if(root == NULL) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long subSum = root->val + left + right;

        long long product = subSum * (totalSum - subSum);
        maxiProduct = max( maxiProduct, product);
            return subSum;
    }

    int maxProduct(TreeNode* root) {
         totalSum = getTotalSum(root);
         dfs(root);
         return maxiProduct % modulo;
    }
};