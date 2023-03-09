//* https://leetcode.com/problems/palindrome-linked-list/description/
//* https://leetcode.com/problems/palindrome-linked-list/editorial/
//* https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

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

    // slow-fast technique or two-runners pointer technique
    public ListNode findMid(ListNode head){
        ListNode slow, fast;
        slow = fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
    public ListNode reverseList(ListNode midNode){
        ListNode prev = null;
        ListNode curr = midNode;
        ListNode Next;

        while(curr != null){
            Next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }
    public boolean isPalindrome(ListNode head) {
        if(head.next == null){
            return true;
        }

        ListNode midNode = findMid(head);

        ListNode left = head;
        ListNode right = reverseList(midNode);

        while(right != null){
            if(left.val != right.val){
                return false;
            }

            left = left.next;
            right = right.next;
        }

        return true;
    }
}