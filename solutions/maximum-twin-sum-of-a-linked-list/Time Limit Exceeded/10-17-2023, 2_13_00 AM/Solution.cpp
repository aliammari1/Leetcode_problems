// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode *parc = head,*parcEnd = head;
        int len = 1,index = 0,max = 0,indexEnd = 0,end = 0;
        while(parc->next != nullptr)
        {
            parc = parc->next;
            len++;
        }
        max = head->val + parc->val;
        parc = head;
        end = len;
        while(index < len / 2)
        {
            index++;
            end--;
            indexEnd = 0;
            parcEnd = head;
            while(indexEnd != end)
            {
                parcEnd = parcEnd->next;
                indexEnd++;
            }
            if(max < parcEnd->val + parc->val)
                max = parcEnd->val + parc->val;
            parc=parc->next;
        }
        return max;
    }
};