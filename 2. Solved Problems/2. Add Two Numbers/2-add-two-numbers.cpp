//* https://leetcode.com/problems/add-two-numbers/description/
//* https://leetcode.com/problems/add-two-numbers/editorial/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* sumHead = NULL;
        ListNode* sumTail = NULL;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            int temp = carry;
            if(l1 != NULL){
                temp = temp + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                temp = temp + l2->val;
                l2 = l2->next;
            }

            carry = temp/10;
            int value = temp%10;
            struct ListNode* curr = new ListNode(value);

            if(sumHead == NULL){
                sumHead = curr;
                sumTail = curr;
            }
            else{
                sumTail->next = curr;
                sumTail = curr;
            }
        }

        return sumHead;
    }
};