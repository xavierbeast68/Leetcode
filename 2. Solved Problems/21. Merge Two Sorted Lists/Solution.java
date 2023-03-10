//* https://leetcode.com/problems/merge-two-sorted-lists/description/
//* https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode mergedLL = new ListNode(-1);
        ListNode temp = mergedLL;

        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                // ListNode tempo = new ListNode(list1.val);
                // temp.next = tempo;
                temp.next = new ListNode(list1.val);
                temp = temp.next;
                list1 = list1.next;
            }
            else{
                // ListNode tempo = new ListNode(list2.val);
                // temp.next = tempo;
                temp.next = new ListNode(list2.val);
                temp = temp.next;
                list2 = list2.next;
            }
        }

        while(list1 != null){
            // ListNode tempo = new ListNode(list1.val);
            // temp.next = tempo;
            temp.next = new ListNode(list1.val);
            temp = temp.next;
            list1 = list1.next;
        }
        while(list2 != null){
            // ListNode tempo = new ListNode(list2.val);
            // temp.next = tempo;
            temp.next = new ListNode(list2.val);
            temp = temp.next;
            list2 = list2.next;
        }

        return mergedLL.next;
    }
}