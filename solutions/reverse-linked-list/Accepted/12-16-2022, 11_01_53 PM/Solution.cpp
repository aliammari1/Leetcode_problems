// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* parch = head;
        list<int> l;
        while(parch!=nullptr)
        {
            l.push_back(parch->val);
            parch=parch->next;
        }
        l.reverse();
        ListNode* l3 = new ListNode(*l.begin());
        ListNode* parc = l3;
        auto it = l.begin();
        it++;
        for(;it != l.end();it++)
        {
            parc->next = new ListNode(*it);
            parc = parc->next;
        }
        return l3;
    }
};