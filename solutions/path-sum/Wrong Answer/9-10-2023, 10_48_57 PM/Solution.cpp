// https://leetcode.com/problems/path-sum

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
    void pathSum(TreeNode *root,int& sum,int& targetSum,bool& found)
    {
        if(root == nullptr) return;
        sum += root->val;
        cout << sum << " " << root->val << endl;
        if(sum == targetSum)
            found = true;
        if(root->left == nullptr && root->right == nullptr)
            sum -= root->val;
        pathSum(root->left,sum,targetSum,found);
        pathSum(root->right,sum,targetSum,found);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        int sum = 0;
        bool found = false;
        pathSum(root,sum,targetSum,found);
        return found;
    }
};