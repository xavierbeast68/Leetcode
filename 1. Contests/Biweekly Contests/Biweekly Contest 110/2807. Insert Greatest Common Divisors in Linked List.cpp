//* https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *prev = head, *curr = head->next;
        
        while(curr != NULL){
            int gcdAB = __gcd(prev->val, curr->val);
            ListNode *newNode = new ListNode(gcdAB);
            
            // changing links
            newNode->next = prev->next;
            prev->next = newNode;
            
            
            // progress
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};