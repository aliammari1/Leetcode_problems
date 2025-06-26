// https://leetcode.com/problems/same-tree

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
    void traverse(TreeNode *node,vector<int>& v)
    {
        if(node == nullptr) return;
        traverse(node->left,v);
        v.push_back(node->val);
        traverse(node->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        vector<int> v1,v2;
        traverse(p,v1);
        traverse(q,v2);
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v1.size();i++)
            if(v1[i] != v2[i])
                return false;
        return true;
    }
};