//* https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        int ind = 0;
        while(fast != NULL && fast->next != NULL){
            if(slow == fast && ind != 0){
                return true;
            }

            slow = slow->next;
            fast = fast->next->next;
            ind++;
        }
        return false;
    }
};