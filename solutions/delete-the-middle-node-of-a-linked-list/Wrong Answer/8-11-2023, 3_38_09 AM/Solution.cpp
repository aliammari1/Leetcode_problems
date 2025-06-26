// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    if(head->next == nullptr) return nullptr;
    ListNode *parc = head,*prev = nullptr;
    int middle = 0,size = 0;
    int i = 0;
    while(parc != nullptr)
    {
        parc = parc->next;
        size++;
    }
    middle = ((size / 2) % 2) == 1 ? ((size / 2) + 1) : (size / 2);
    parc = head;
    if(size % 2)
    {
    while(i < middle-2 && i < size - 1)
    {
        prev = parc;
        parc = parc->next;
        i++;
    }
    }    
    else
    {
    while(i < middle && i < size - 1)
    {
        prev = parc;
        parc = parc->next;
        i++;
    }
    }
   if(parc != nullptr)
    {
    prev->next = parc->next;
    parc->next = nullptr;
    }
    return head;
    }
};