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
    void symmetric(TreeNode *root1,TreeNode *root2,TreeNode* root,bool& sym)
    {
        if(root1 == nullptr && root2 == nullptr) return;
        if(root1 == nullptr && root2 != nullptr) 
        {
        sym = false;
        return;
        }
        if(root2 == nullptr && root1 != nullptr) 
        {
        sym = false;
        return;
        }
        if(root1->val != root2->val) sym = false;
        symmetric(root1->left,root2->right,root,sym);
        if(root1 == root || root2 == root) return;
        symmetric(root1->right,root2->left,root,sym);
    }
    bool isSymmetric(TreeNode* root) {
        bool sym = true;
        symmetric(root,root,root,sym);
        return sym;
    }
};
