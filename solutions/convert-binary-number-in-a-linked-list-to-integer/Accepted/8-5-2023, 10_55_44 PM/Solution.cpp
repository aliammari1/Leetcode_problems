// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
    int getDecimalValue(ListNode* head) {
        ListNode* parc = head;
        int power = 1;
        int value = 0;
        while(parc != nullptr)
        {
            parc=parc->next;
            power *= 2;
        }
        while(head != nullptr)
        {
            power /= 2;
            value += head->val * power;
            head = head->next;
        }
        return value;
    }
};