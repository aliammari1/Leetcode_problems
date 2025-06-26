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
        int size = 0,i = 0;
        while(parc != nullptr)
        {
            parc = parc->next;
            size++;
        }
        size = size / 2;
        parc = head;
        while(i < size && parc->next != nullptr)
        {
            prev = parc;
            parc = parc->next;
            i++;
        }
        prev->next = parc->next;
        return head;
    }
};