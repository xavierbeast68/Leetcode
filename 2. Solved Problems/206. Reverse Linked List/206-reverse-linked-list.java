//* https://leetcode.com/problems/reverse-linked-list/
//* https://www.geeksforgeeks.org/reverse-a-linked-list/
//* https://www.youtube.com/watch?v=iRtLEoL-r-g&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=t7YaoQOFXzk&ab_channel=ApnaCollege

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
    public ListNode reverseList(ListNode head) {
        if(head == null){
            return head;
        }
        if(head.next == null){
            return head;
        }

        ListNode prev, curr, Next;
        prev = null;
        curr = head;

        while(curr !=  null){
            Next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = Next;
        }

        head = prev;
        return head;
    }
}