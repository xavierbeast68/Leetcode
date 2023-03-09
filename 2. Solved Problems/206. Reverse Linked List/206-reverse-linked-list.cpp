//* https://leetcode.com/problems/reverse-linked-list/
//* https://www.geeksforgeeks.org/reverse-a-linked-list/
//* https://www.youtube.com/watch?v=iRtLEoL-r-g&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=t7YaoQOFXzk&ab_channel=ApnaCollege

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }

        ListNode *prev, *curr, *Next;
        prev = NULL;
        curr = head;

        while(curr !=  NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        head = prev;
        return head;
    }
};