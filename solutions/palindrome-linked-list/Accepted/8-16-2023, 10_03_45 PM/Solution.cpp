// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        string s = "";
        while(head != nullptr)
        {
            s += to_string(head->val);
            head = head->next;
        }
        int length = s.length();
        for(int i = 0;i < length;i++)
            if(s[i] != s[length - 1 - i])
                return false;
        return true;
    }
};