// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *parc = head,*prev = head;
        while(parc != nullptr && parc->next != nullptr)
        {
            parc = parc->next->next;
            prev = prev->next;
            swap(parc->val,prev->val);
        }
        parc = head;
        while(parc != nullptr && parc->next != nullptr)
        {
            if(parc->next->next == nullptr)
                swap(parc->val,parc->next->val);
            parc = parc->next;
        }
        return head;
    }
};