// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *parc = head,*prev = nullptr;
        while(parc->next != nullptr)
        {
            prev = parc;
            parc = parc->next;
            ListNode* node = new ListNode(gcd(prev->val,parc->val));
            prev->next = node;
            node->next = parc;
        }
        return head;
    }
};