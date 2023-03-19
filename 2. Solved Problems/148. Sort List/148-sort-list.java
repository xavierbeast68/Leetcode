//* https://leetcode.com/problems/sort-list/description/

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
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }

        ListNode midNode = calMid(head);

        ListNode newRight = sortList(midNode.next);
        midNode.next = null;
        ListNode newLeft = sortList(head);

        return merge(newLeft, newRight);
    }

    public ListNode calMid(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }

        return slow;
    }

    public ListNode merge(ListNode l1, ListNode l2){
        ListNode mergedLL = new ListNode(-1);
        ListNode temp = mergedLL;
        
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                temp.next = l1;
                temp = temp.next;
                l1 = l1.next;
            } else{
                temp.next = l2;
                temp = temp.next;
                l2 = l2.next;
            }
        }

        while(l1 != null){
            temp.next = l1;
            temp = temp.next;
            l1 = l1.next;
        }
        while(l2 != null){
            temp.next = l2;
            temp = temp.next;
            l2 = l2.next;
        }

        return mergedLL.next;
    }
}