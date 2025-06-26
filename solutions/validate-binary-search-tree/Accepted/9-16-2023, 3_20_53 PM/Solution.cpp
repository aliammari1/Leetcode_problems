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
    void traverse(TreeNode* root,vector<int>& v,int& i,bool& test)
    {
        if(root == nullptr) return;
        traverse(root->left,v,i,test);
        v.push_back(root->val);
        if(i != 0 && v[i - 1] >= v[i])
            test = false;
        i++;
        traverse(root->right,v,i,test);
    }
    bool isValidBST(TreeNode* root) {
        bool test = true;
        vector<int> v;
        int i =0;
        traverse(root,v,i,test);
        return test;
    }
};