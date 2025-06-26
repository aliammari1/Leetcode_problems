// https://leetcode.com/problems/validate-binary-search-tree

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
    void traverse(TreeNode* root,bool& test)
    {
        if(root == nullptr) return;
        if((root->left != nullptr && root->val <= root->left->val) || (root->right != nullptr && root->val >= root->right->val))
        {
            test = false;
            return;
        }
        traverse(root->left,test);
        traverse(root->right,test);
    }
    bool isValidBST(TreeNode* root) {
        bool test = true;
        traverse(root,test);
        return test;
    }
};