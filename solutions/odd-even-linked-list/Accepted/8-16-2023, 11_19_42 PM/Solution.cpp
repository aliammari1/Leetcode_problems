// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *OddList = new ListNode(head->val),*EvenList = new ListNode(head->next->val);
        ListNode *parc = head,*parcOdd = OddList,*parcEven = EvenList;
        int i = 0;
        while(parc != nullptr && parc->next != nullptr)
        {
            parc = parc->next->next;
            if(parc!=nullptr)
            {
            ListNode *node = new ListNode(parc->val,nullptr);
            parcOdd->next = node;
            parcOdd = parcOdd->next;
            }
        }
        parc = head->next;
        while(parc != nullptr && parc->next != nullptr)
        {
            parc = parc->next->next;
            if(parc!=nullptr)
            {
            ListNode *node = new ListNode(parc->val,nullptr);
            parcEven->next = node;
            parcEven = parcEven->next;
            }
        }
        parcOdd->next = EvenList;
        return OddList;
    }
};