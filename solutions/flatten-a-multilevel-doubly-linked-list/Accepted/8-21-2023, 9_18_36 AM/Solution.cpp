// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* parc = head;
        while(parc != nullptr)
        {
            if(parc->child != nullptr)
            {
                Node*next = parc->next,*parcChild = parc->child;
                parc->next = parcChild;
                parcChild->prev = parc;
                while(parcChild != nullptr && parcChild->next != nullptr)
                {
                    parcChild = parcChild->next;
                }
                parcChild->next = next;
                if(next != nullptr)
                next->prev = parcChild;
                parc->child = nullptr;
            }
            parc = parc->next;
        }
        return head;
    }
};