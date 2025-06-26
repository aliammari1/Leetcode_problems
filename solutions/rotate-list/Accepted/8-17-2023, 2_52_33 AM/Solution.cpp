// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *start = head,*end = head;
        int size = 1;
        while(end->next != nullptr)
        {
            end = end->next;
            size++;
        }
        k = k % size;
        for(int i = 0;i < k;i++)
        {
        while(start != nullptr)
        {
            swap(start->val,end->val);
            start = start->next;
        }
        start = head;
        }
        return head;
    }
};