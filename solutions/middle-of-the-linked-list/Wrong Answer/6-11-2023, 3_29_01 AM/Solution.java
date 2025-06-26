// https://leetcode.com/problems/middle-of-the-linked-list

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode med = null,parc = head;
        int n = 1;
        while(parc.next != null)
            {
                parc = parc.next;
                n++;
            }
        int mid = (n / 2) + 1;
        n=1;
        parc = head;
        while(parc.next != null)
        {
            if(mid == n)
            {
                med = parc;
                break;
            }
            parc = parc.next;
            n++;
        }
        return med;
    }
}