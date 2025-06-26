// https://leetcode.com/problems/n-ary-tree-postorder-traversal

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
    void postorderTraversal(Node* root,vector<int>& v)
    {
        for(Node* node : root->children)
        {
            postorderTraversal(node,v);
            v.push_back(node->val);
        }
    }
    vector<int> postorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> v;
        postorderTraversal(root,v);
        v.push_back(root->val);
        return v;
    }
};