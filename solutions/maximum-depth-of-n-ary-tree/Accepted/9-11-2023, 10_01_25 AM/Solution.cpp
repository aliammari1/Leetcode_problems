// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

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
    void maxD(Node* root,int& depth,int& max)
    {
        if(root == nullptr)
            return;
        for(Node* node : root->children)
        {
            // cout << node->val << " " << node->children.empty() << endl;
            depth++;
            maxD(node,depth,max);
            depth--;
            if(depth > max)
                max = depth;
            cout << depth  << " " << node->val << endl;
        }
    }
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        if(root->children.empty()) return 1;
        int max = 0,depth = 2;
        maxD(root,depth,max);
        return max;
    }
};