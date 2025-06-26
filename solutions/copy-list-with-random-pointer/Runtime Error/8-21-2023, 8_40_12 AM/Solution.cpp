// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newList = new Node(head->val),*parcOriginal = head,*parcCopy = newList;
        while(parcOriginal->next != nullptr)
        {
            Node *node = new Node(parcOriginal->next->val);
            parcCopy->next = node;
            parcCopy = parcCopy->next;
            parcOriginal = parcOriginal->next;
        }
        parcCopy = newList;
        parcOriginal = head;
        int index = 0,indexCopy = 0;
        while(parcCopy != nullptr)
        {
        if(parcOriginal->random == nullptr)
            parcCopy->random = nullptr;
        else
        {
        index = 0;
        indexCopy = 0;
        Node *parcRandom = parcOriginal->random,*parcSearch = head;
        while(parcSearch != nullptr && parcSearch != parcRandom)
        {
            parcSearch = parcSearch->next;
            index++;
        }
        parcSearch = newList;
        while(indexCopy <= index)
        {
            if(index == indexCopy)
            parcCopy->random = parcSearch;
            parcSearch = parcSearch->next;
            indexCopy++;
        }
        }
        parcOriginal = parcOriginal->next;
        parcCopy = parcCopy->next;
        }
        return newList;
    }
};