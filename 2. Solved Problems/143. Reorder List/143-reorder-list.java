//* https://leetcode.com/problems/reorder-list/
//* https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

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
    public void reorderList(ListNode head) {

        // cal mid
        ListNode slow, fast;
        slow = fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode midNode = slow;

        // reverse 2nd half
        ListNode prev = null;
        ListNode curr = midNode.next;
        midNode.next = null; // breaking link between two halfs
        ListNode Next;
        while(curr != null){
            Next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = Next;
        }

        ListNode right = prev;  // reversed 2nd half head
        ListNode left = head; // first half

        // alternate merge
        ListNode nextL, nextR;
        while(left != null && right != null){
            nextL = left.next;
            left.next = right;
            nextR = right.next;
            right.next = nextL;

            // updation
            left = nextL;
            right = nextR;
        }
    }
}