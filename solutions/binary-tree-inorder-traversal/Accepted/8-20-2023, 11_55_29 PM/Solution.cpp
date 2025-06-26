// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    void traversal(vector<int>& v,TreeNode* node)
    {
        if(node == nullptr) return;
        traversal(v,node->left);
        v.push_back(node->val);
        traversal(v,node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(v,root);
        return v;
    }
};