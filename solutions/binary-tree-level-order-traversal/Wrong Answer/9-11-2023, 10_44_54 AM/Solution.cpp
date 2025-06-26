// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> v;
        v.push_back({root->val});
        int row = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            vector<int> vec;
            if(curr->left != nullptr)
            {
                vec.push_back(curr->left->val);
                q.push(curr->left);
            }
            if(curr->right != nullptr)
            {
                vec.push_back(curr->right->val);
                q.push(curr->right);
            }
            if(!vec.empty())
            v.push_back(vec);
        }
        return v;
    }
};