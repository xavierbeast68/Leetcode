//* https://leetcode.com/problems/reorder-list/
//* https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/


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
    void reorderList(ListNode* head) {
        
        // cal mid
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *midNode = slow;

        // reverse 2nd half
        ListNode *prev = NULL;
        ListNode *curr = midNode->next;
        midNode->next = NULL; // breaking link between two halfs
        ListNode *Next;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        ListNode *right = prev;  // reversed 2nd half head
        ListNode *left = head; // first half

        // alternate merge
        ListNode *nextL, *nextR;
        while(left != NULL && right != NULL){
            nextL = left->next;
            left->next = right;
            nextR = right->next;
            right->next = nextL;

            // updation
            left = nextL;
            right = nextR;
        }
    }
};