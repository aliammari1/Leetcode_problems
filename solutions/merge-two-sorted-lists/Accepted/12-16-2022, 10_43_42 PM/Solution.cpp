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
        list<int> l;
        ListNode* parc1 = list1;
        ListNode* parc2 = list2;
        while(parc1 != nullptr)
        {
            l.push_back(parc1->val);
            parc1=parc1->next;
        }
        while(parc2 != nullptr)
        {
            l.push_back(parc2->val);
            parc2=parc2->next;
        }
        l.sort();
        ListNode *list3 = new ListNode(*(l.begin()));
        ListNode* parc = list3;
        auto it = l.begin();
        it++;
        for(; it!= l.end(); it++)
        {
            parc->next = new ListNode(*it);
            parc = parc->next;
        }
        return list3;
    }
};