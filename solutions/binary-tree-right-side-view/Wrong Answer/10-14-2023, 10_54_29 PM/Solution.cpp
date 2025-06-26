// https://leetcode.com/problems/binary-tree-right-side-view

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
    void traverse_right(TreeNode* head,TreeNode* node,vector<int>& v)
    {
        if(node == nullptr || head == node) return;
        //cout << node->val << endl;
        v.push_back(node->val);
        traverse_right(head,node->right,v);
        traverse_right(head,node->left,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return vector(0,0);
        vector<int> v;
        v.push_back(root->val);
        if(root->right != nullptr)
        traverse_right(root,root->right,v);
        else
        traverse_right(root,root->left,v);
        return v;
    }
};