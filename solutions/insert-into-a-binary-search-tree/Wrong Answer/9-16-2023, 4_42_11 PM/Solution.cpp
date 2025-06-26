// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->val > val)
            root->left = new TreeNode(val);
        if(root->right == nullptr && root->val < val)
            root->right = new TreeNode(val);
        if(root->val < val)
            insertIntoBST(root->right,val);
        else
            insertIntoBST(root->left,val);
        return root;
    }
};