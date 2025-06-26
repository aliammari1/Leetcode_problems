// https://leetcode.com/problems/symmetric-tree

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
    int symetric(TreeNode* node)
    {
        if(node == nullptr) 
            return 0;
        return node->val;
    }
    bool isSymmetric(TreeNode* root) {
        if(symetric(root->left) != symetric(root->right))
            return false;
        return true;
    }
};