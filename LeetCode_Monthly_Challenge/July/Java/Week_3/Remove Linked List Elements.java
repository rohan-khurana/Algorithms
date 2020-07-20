/*
PROBLEM:
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/



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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null) return head;
        ListNode prev = null, curr = head;
        while(curr != null){
            if(curr.val == val)
                if(prev == null) head = curr.next;
                else prev.next = curr.next;
            else
                prev = curr;
            curr = curr.next;
        }
        return head;
    }
}
