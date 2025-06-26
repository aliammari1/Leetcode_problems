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
        map<int*,int> m;
        while(headA != nullptr)
        {
            m.insert(pair<int*,int>(&headA->val,headA->val));
            headA = headA->next;
        }

        while(headB != nullptr)
        {
            if(m.find(&headB->val) != m.end())
                return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};