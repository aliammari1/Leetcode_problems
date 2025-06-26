// https://leetcode.com/problems/merge-nodes-in-between-zeros

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*parc = head,*newHead = nullptr,*parcNewHead = nullptr;
        bool headCreated = false;
        int sum = 0;
        while(parc->next != nullptr)
        {
            if(parc->val == 0)
                sum = 0;
            else
                sum += parc->val;
            if(parc->next->val == 0 && !headCreated)
            {
                newHead = new ListNode(sum);
                parcNewHead = newHead;
                headCreated = true;
            }
            else if(parc->next->val == 0 && headCreated)
            {
                parcNewHead->next = new ListNode(sum);
                parcNewHead = parcNewHead->next;
            }
            parc = parc->next;
        }
        return newHead;
    }
};