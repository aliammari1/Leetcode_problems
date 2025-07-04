// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev = nullptr,*parc = head,*suiv = head->next;
        while(parc->next != nullptr)
        {
            cout << parc->val << endl;
            prev = parc;
            parc = parc->next;
            parc->next = prev;
            parc = suiv;
        }
        return head;
    }
};

