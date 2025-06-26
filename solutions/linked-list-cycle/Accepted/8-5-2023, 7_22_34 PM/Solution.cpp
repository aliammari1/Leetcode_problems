// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        map<int*,int> m;
        m.insert(pair<int*,int>(&head->val,head->val));
        while(head != nullptr)
        {
            head = head->next;
            if(head != nullptr)
            {
            if(m.find(&head->val) != m.end())
                return true;
            m.insert(pair<int*,int>(&head->val,head->val));
            }
        }
        return false;
    }
};