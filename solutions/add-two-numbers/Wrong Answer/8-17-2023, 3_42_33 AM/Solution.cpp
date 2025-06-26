// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0),*head = l3;
        int carry = 0,value = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            value = l1->val + l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value%10);
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }        
        while(l1 != nullptr)
        {
            value = l1->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value%10);
            l1 = l1->next;
            l3 = l3->next;
        }
        while(l2!= nullptr)
        {
            value = l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value%10);
            l2 = l2->next;
            l3 = l3->next;
        }
        head = head->next;
        return head;
        
    }
};