// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow = head;
        bool found = false;
        while(fast!= nullptr && fast->next != nullptr)
        {
            fast = (!found) ? fast->next->next : fast->next;
            slow = slow->next;
            if(slow == fast && !found)
            {
                found = true;
                fast = head;
            }
            else if(slow == fast && found)
                return slow;
        }
        return nullptr;
    }
};