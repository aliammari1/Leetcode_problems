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
        int row = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> vec;
            int size = q.size();
            for(int i = 0;i < size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
                vec.push_back(curr->val);
            }
            v.push_back(vec);
        }
        return v;
    }
};