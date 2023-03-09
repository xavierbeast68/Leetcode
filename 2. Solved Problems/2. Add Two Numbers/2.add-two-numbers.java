//* https://leetcode.com/problems/add-two-numbers/description/
//* https://leetcode.com/problems/add-two-numbers/editorial/

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode sumHead = null;
        ListNode sumTail = null;
        int carry = 0;
        while(l1 != null || l2 != null || carry == 1){
            int temp = carry;
            if(l1 != null){
                temp = temp + l1.val;
                l1 = l1.next;
            }
            if(l2 != null){
                temp = temp + l2.val;
                l2 = l2.next;
            }

            carry = temp/10;
            int value = temp%10;
            ListNode curr = new ListNode(value);

            if(sumHead == null){
                sumHead = curr;
                sumTail = curr;
            }
            else{
                sumTail.next = curr;
                sumTail = curr;
            }
        }

        return sumHead;
    }
}