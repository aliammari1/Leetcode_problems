// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

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
        q1 = q;
        // cout << q1.front() << " " << q.front() << endl;
        while(!q.empty())
        {
            int size = q.size();
            // cout << "size: " << size << endl;
            q1 = q;
            for(int i = 0;i < size;i++)
            {
            Node* curr = q.front(),*nextCurr = nullptr;
            if(i==0)
                q1.pop();
            if(q1.empty())
                nextCurr = nullptr;
            else
            {
                nextCurr = q1.front();
            }
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
            // cout << "i: " << i << " " << curr->val << " " << nextCurr->val << " ";
            // if(i % 2 == 0 && curr->right != nullptr)
            // {
            //     // cout << curr->right->val << " ";
            //     left = curr->right;
            // }
            // if(i % 2 == 1 && left != nullptr)
            //     left->next = curr->left;
            // if(curr->left != nullptr)
            //     curr->left->next = curr->right;
            curr->next = nextCurr;
            q.pop();
            q1.pop();
            }
            cout << endl;
        }
        return root;
    }
};