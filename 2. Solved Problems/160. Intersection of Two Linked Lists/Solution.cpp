//* https://leetcode.com/problems/intersection-of-two-linked-lists/
//* https://www.youtube.com/watch?v=u4FWXfgS8jw&ab_channel=takeUforward

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};