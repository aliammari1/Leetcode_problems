// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next == nullptr)
            return nullptr;
        ListNode *parc = head;
        map<int*,int> m;
        int i =0;
        while(parc!=nullptr)
        {
            m.insert(m.begin(),pair<int*,int>(&parc->val,parc->val));
            i++;
            if(i>m.size())
            break;
            parc=parc->next;
        }
        return parc;
    }
};































