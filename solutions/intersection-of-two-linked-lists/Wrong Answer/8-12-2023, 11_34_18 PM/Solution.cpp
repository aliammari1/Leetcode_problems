// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool finished = false;
        ListNode *parcA = headA,*parcB = headB;
        while(parcA != nullptr && parcB != nullptr)
        {
        parcA = parcA->next;
        parcB = parcB->next;
        if(parcA == parcB)
        return parcA;
        if(parcA == nullptr)
        parcA = headB;
        if(parcB == nullptr)
        parcB = headA;
        }
        return nullptr;
    }
};