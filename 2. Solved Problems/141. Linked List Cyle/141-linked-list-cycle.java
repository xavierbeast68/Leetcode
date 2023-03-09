//* https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow, fast;
        slow = fast = head;
        int ind = 0;
        while(fast != null && fast.next != null){
            if(slow == fast && ind != 0){
                return true;
            }

            slow = slow.next;
            fast = fast.next.next;
            ind++;
        }
        return false;
    }
}