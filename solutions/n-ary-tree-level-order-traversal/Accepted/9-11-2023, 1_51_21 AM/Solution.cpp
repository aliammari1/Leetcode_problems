// https://leetcode.com/problems/n-ary-tree-level-order-traversal

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
    void levelOrderTraversal(Node* root,queue<Node*>& q,vector<vector<int>>& v,int& row)
    {
        if(root == nullptr) return;
        int start = 0;
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            // cout << curr->val << " " << row << endl;
            v[row].push_back(curr->val);
            for(Node* node : curr->children)
            {
                q.push(node);
                start++;
            }
            // cout << start << endl;
            if(q.size() == start)
            {
                row++;
                v.push_back({});
                start = 0;
            }
        }
        v.pop_back();
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        vector<vector<int>> v;
        v.push_back({});
        queue<Node*> q;
        q.push(root);
        int row = 0;
        levelOrderTraversal(root,q,v,row);
        return v;
    }
};