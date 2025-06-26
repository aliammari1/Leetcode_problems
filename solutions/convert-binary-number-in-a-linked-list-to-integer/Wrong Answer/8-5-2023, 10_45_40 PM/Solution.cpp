// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        int power = 1;
        int value = 0;
        while(head != nullptr)
        {
            s.push(head->val);
            head=head->next;
            power *= 2;
        }
        while(!s.empty())
        {
            power /= 2;
            value += s.top() * power;
            s.pop();
        }
        return value;
    }
};