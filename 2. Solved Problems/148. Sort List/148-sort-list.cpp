//* https://leetcode.com/problems/sort-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int->val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* calMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* mergedLL = new ListNode(-1);
        ListNode* temp = mergedLL;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            } else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }

        while(l1 != NULL){
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }

        return mergedLL->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *midNode = calMid(head);

        ListNode *newRight = sortList(midNode->next);
        midNode->next = NULL;
        ListNode *newLeft = sortList(head);

        return merge(newLeft, newRight);
    }
};