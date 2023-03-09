//* https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//* https://www.youtube.com/watch?v=XVuQxVej6y8&ab_channel=NeetCode
//* https://www.youtube.com/watch?v=Lhu3MsXZy-Q&ab_channel=takeUforward
//* https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz= 0;
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        
        if(n == sz){ // remove first
            // head = head->next;
            return head->next;
        }

        int idx = sz - n;
        int i = 1; // on first node
        ListNode *prev = head;
        while(i < idx){
            prev = prev->next;
            i++;
        }

        prev->next = prev->next->next;
        return head;
    }
};