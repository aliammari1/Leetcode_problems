// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
    vector<int> v;
    int i = -1;
public:
    BSTIterator(TreeNode* root) {
        treeVector(root);
    }
    
    int next() {
        i++;
        return v[i];
    }
    
    bool hasNext() {
        return i != v.size() - 1;
    }
    
    void treeVector(TreeNode* root)
    {
        if(root == nullptr) return;
        treeVector(root->left);
        v.push_back(root->val);
        treeVector(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */