// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        ListNode* parc = head;
        int s = 0;
        while(parc!=nullptr)
        {
            s++;
            parc=parc->next;
        }
        s = (s / 2);
        cout << s;
        int x = 0;
        parc = head;
        while(x != s)
            {
                parc=parc->next;
                x++;
            }
        return parc;
    }
};