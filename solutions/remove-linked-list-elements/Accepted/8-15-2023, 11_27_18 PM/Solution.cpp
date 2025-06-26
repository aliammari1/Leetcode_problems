// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        while(head != nullptr && head->val == val)
            head = head->next;
        ListNode *parc = head,*prec = nullptr;
        while(parc != nullptr && parc->next != nullptr)
        {
            if(parc->next->val == val)
            {
                parc->next = parc->next->next;
                continue;
            }
            parc = parc->next;
        }
        return head;
    }
};
