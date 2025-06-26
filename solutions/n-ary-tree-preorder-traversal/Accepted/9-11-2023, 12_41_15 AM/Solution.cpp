// https://leetcode.com/problems/n-ary-tree-preorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorderTraversal(Node*root , vector<int>& v)
    {
        for(Node* node : root->children)
        {
            v.push_back(node->val);
            preorderTraversal(node,v);
        }
    }
    vector<int> preorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> v;
        v.push_back(root->val);
        preorderTraversal(root,v);
        return v;
    }
};