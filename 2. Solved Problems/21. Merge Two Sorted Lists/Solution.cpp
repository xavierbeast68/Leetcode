//* https://leetcode.com/problems/merge-two-sorted-lists/description/
//* https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *mergedLL = new ListNode(-1);
        ListNode *temp = mergedLL;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                // ListNode *tempo = new ListNode(list1->val);
                // temp->next = tempo;
                temp->next = new ListNode(list1->val);
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                // ListNode *tempo = new ListNode(list2->val);
                // temp->next = tempo;
                temp->next = new ListNode(list2->val);
                temp = temp->next;
                list2 = list2->next;
            }
        }

        while(list1 != NULL){
            // ListNode *tempo = new ListNode(list1->val);
            // temp->next = tempo;
            temp->next = new ListNode(list1->val);
            temp = temp->next;
            list1 = list1->next;
        }
        while(list2 != NULL){
            // ListNode *tempo = new ListNode(list2->val);
            // temp->next = tempo;
            temp->next = new ListNode(list2->val);
            temp = temp->next;
            list2 = list2->next;
        }

        return mergedLL->next;
    }
};