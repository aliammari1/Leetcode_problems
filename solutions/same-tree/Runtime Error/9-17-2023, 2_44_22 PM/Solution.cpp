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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        if(q1.front()->val != q2.front()->val)
        {
            return false;
        }
        while(!q1.empty() && !q2.empty())
        {
            TreeNode* curr1 = q1.front();
            TreeNode* curr2 = q2.front();
            q1.pop();
            q2.pop();
            if(curr1->left == nullptr && curr2->left != nullptr)
            return false;
            if(curr1->right == nullptr && curr2->right != nullptr)
            return false;
            if(curr1->left != nullptr && curr2->left != nullptr)
            {
                if(curr1->left->val == curr2->left->val)
                {
                    q1.push(curr1->left);
                    q2.push(curr2->left);
                }
                else
                    return false;
            }
            if(curr1->right != nullptr && curr2->right != nullptr)
            {
                if(curr1->right->val == curr2->right->val)
                {
                    q1.push(curr1->right);
                    q2.push(curr2->right);
                }
                else
                    return false;
            }
        }
        return true;
    }
};