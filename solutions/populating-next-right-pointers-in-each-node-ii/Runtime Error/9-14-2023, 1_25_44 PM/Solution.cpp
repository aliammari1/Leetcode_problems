// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> q,q1;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            q1 = queue<Node*>(q);
            q1.pop();
            for(int i = 0;i < size;i++)
            {
            Node* curr = q.front(),*nextCurr = nullptr;
            if(q1.empty())
                nextCurr = nullptr;
            else
                nextCurr = q1.front();
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
            curr->next = nextCurr;
            q.pop();
            q1.pop();
            }
        }
        return root;
    }
};