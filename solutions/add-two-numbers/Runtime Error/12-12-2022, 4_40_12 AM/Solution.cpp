// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s = "";
        ListNode* parc = new ListNode();
        parc = l1;
        while(parc!=nullptr)
        {
            s+=to_string(parc->val);
            parc = parc->next;
        }
        reverse(s.begin(),s.end());
        unsigned long long x = stoll(s);
        parc = l2;
        s="";
        while(parc!=nullptr)
        {
            s+=to_string(parc->val);
            parc = parc->next;
        }
        reverse(s.begin(),s.end());
        unsigned long long y = stoll(s);
        unsigned long long z = x + y;
        s=to_string(z);
        ListNode *l3 = new ListNode(stoi(s.substr(s.size()-1,1)));
        parc = l3;
        int i = 1;
        while(i != s.size())
        {
            parc->next = new ListNode(stoi(s.substr(s.size()-i-1,1)));
            parc = parc->next;
            i++;
        }
        return l3;
    }
};