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
        ListNode* prev = nullptr,*courant = head;
        bool deleted = false;
        while(courant != nullptr)
        {
            //cout << courant->val << endl;
            if(!deleted)
            {
                prev = courant;
                courant = courant->next;
            }
            deleted = false;
            if(courant != nullptr && prev->val == courant->val)
            {
                prev->next = courant->next;
                courant = courant->next;
                deleted = true;
            }
        }
        return head;
    }
};