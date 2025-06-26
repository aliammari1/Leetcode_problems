// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head,*courant = head->next;
        while(courant != nullptr)
        {
           // cout << courant->val << endl;
            if(prev->val == courant->val)
            {
                prev->next = courant->next;
                //courant->next = nullptr;
                courant = prev->next;
            }
            prev = courant;
            if(courant!= nullptr)
                courant = courant->next;
        }
        return head;
    }
};