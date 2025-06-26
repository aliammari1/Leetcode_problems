// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        
        if(list1 == nullptr && list2 != nullptr)
            return list2;
        
        if(list1 != nullptr && list2 == nullptr)
            return list1;
            
            int i =0;
            ListNode* list3 = new ListNode();
            ListNode* parc = list3;
            ListNode* parc1 = list1;
            ListNode* parc2 = list2;
        while(parc1 != nullptr && parc2 != nullptr)
        {
            if(parc1->val < parc2->val)
            {
                parc->val = parc1->val;
                parc->next = parc1;
                parc = parc->next;
                parc1=parc1->next;
            }
            else
            {
                parc->val = parc2->val;
                parc->next = parc2;
                parc = parc->next;
                parc2=parc2->next;
            }
        }
        return list3;
    }
};