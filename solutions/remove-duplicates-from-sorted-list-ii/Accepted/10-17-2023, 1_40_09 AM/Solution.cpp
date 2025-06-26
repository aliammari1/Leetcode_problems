// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
        ListNode* parc = head,*prev = nullptr,*newHead = nullptr,*parcNewHead = nullptr;
        bool found = false,headCreated = false;
        while(parc != nullptr)
        {
            while(parc->next != nullptr && parc->val == parc->next->val)
            {
                parc = parc->next;
                found = true;
                //cout << parc->val << endl;
            }
            
            if(found) 
            {
                parc = parc->next;
                found = false;
                continue;
            }
            if(!headCreated)
            {
                newHead = new ListNode(parc->val);
                parcNewHead = newHead;
                headCreated = true;
            }
            else
            {
                parcNewHead->next = new ListNode(parc->val);
                parcNewHead = parcNewHead->next;
            }
            parc = parc->next;
        }
        return newHead;
    }
};