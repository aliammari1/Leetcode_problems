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
        while(head != nullptr)
        {
            m.insert(pair<int*,int>(&head->val,head->val));
            head = head->next;
            if(head != nullptr && m.find(&head->val) != m.end())
                return true;
        }
        return false;
    }
};