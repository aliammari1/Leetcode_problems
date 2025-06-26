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
        bool finished1 = false, finished2 = false;
        ListNode *parcA = headA,*parcB = headB;
        while(parcA != nullptr && parcB != nullptr)
        {
        if(parcA == parcB)
        return parcA;
        parcA = parcA->next;
        parcB = parcB->next;
        if(parcA == nullptr && !finished1)
        {
            parcA = headB;
            finished1 = true;
        }
        if(parcB == nullptr && !finished2)
        {
            parcB = headA;
            finished2 = true;
        }
        }
        return nullptr;
    }
};