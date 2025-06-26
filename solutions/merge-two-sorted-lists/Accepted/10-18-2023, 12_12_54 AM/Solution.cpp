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
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode *parc1 = list1,*parc2 = list2,*prev = nullptr;
        int size = 1;
        while(parc1-> next != nullptr)
            parc1 = parc1->next;
        parc1->next = parc2;
        parc1 = list1;
        while(parc1-> next != nullptr)
        {
            parc1 = parc1->next;
            size++;
        }
        int i = 0;
        while(i < size)
        {
        parc1 = list1;
        while(parc1->next != nullptr)
        {
            if(parc1->val > parc1->next->val)
            swap(parc1->val,parc1->next->val);
            parc1 = parc1->next;    
        }
        i++;
        }
        return list1;
    }
};