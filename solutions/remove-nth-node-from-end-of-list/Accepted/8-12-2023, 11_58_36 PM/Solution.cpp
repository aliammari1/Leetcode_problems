// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0,i = 0;
        ListNode *parc = head,*prev = nullptr;
        while(parc!=nullptr)
        {
            parc = parc->next;
            size++;
        }
        n = size - n;
        parc = head;
        while(i < n && parc->next != nullptr)
        {
            prev = parc;
            parc = parc->next;
            i++;
        }
        if(i == 0) head = head->next;
        else if(prev != nullptr) prev->next = parc->next;
        else if(prev == nullptr && n == 1) head = nullptr;
        cout << i << endl;
        return head;
    }
};