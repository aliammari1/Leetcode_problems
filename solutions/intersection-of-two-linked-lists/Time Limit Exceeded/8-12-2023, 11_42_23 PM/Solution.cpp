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
        ListNode *parcA = headA,*parcB = headB;
        while(parcA != parcB)
        {
        if(parcA == parcB)
        return parcA;
        parcA = parcA->next;
        parcB = parcB->next;
        if(parcA == nullptr)
            parcA = headB;
        if(parcB == nullptr)
            parcB = headA;
        }
        return parcA;
    }
};