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
    void traverse(TreeNode* root,TreeNode* head,bool& test)
    {
        if(root == nullptr) return;
        // cout << "test0" << endl;
        if((root->left != nullptr && (root->val <= root->left->val || (root->left->right != nullptr && head->val <= root->left->right->val))))
        {
            // cout << "---------------------test1" << endl;
            test = false;
            return;
        }
        // cout << "test2" << endl;
        if((root->right != nullptr && (root->val >= root->right->val || (root->right->left != nullptr && head->val >= root->right->left->val))))
        {
            // cout << "--------------------test3" << endl;
            test = false;
            return;
        }
        traverse(root->left,head,test);
        traverse(root->right,head,test);
    }
    bool isValidBST(TreeNode* root) {
        bool test = true;
        traverse(root,root,test);
        return test;
    }
};